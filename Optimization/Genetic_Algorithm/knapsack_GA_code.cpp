#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

struct Thing {
    string name;
    int weight; // tinh theo g
};

struct Solution;
int maximum_weight;
int best_solution_limit = 100;

const int number_of_variable = 20;
Thing stuff[number_of_variable] = {
    {"Dien thoai", 200}, {"Laptop", 2200}, {"Keo cao su", 25}, {"Tai nghe", 240}, {"Mu", 70},
    {"Tat", 38}, {"Coc nuoc", 350}, {"Khan giay", 80}, {"May doc sach", 330}, {"May anh", 240},
    {"Chai nuoc", 200}, {"Quan ao", 100}, {"Sac du phong", 220}, {"Den pin", 500}, {"Sach", 150},
    {"Giay", 400}, {"Goi", 50}, {"Hop thuc an", 300}, {"O", 500}, {"Ong nhom", 150}
    };
int mutation_limit = 20;

struct Solution {
    string Genome;
    int fitness_value;
    int roulette_value;
    void random () {
        for(int i = 0; i < number_of_variable; i++)
            Genome += char(rand() % 2 + 48);
        fitness_value = fitness_function();
        roulette_value = fitness_value;
    }

    // Ham danh gia muc do tot cua loi giai
    int fitness_function() {
        int fitness = 0;
        for(int i = 0; i < number_of_variable; i++)
            if(Genome[i] == '1')
                fitness += stuff[i].weight;
        if(fitness > maximum_weight)
            return 0;
        return fitness;
    }
};

void cross_over_function(Solution &A, Solution &B) {
    int k = rand() % number_of_variable;
    string copy = A.Genome;
    for(int i = k; i < number_of_variable; i++)
        A.Genome[i] = B.Genome[i];
    for(int i = k; i < number_of_variable; i++)
        B.Genome[i] = copy[i];
}

void mutation_function (Solution &A) {
    int k = rand() % number_of_variable;
    A.Genome[k] = char(97 - A.Genome[k]);
}


bool cmp(Solution a, Solution b) {
    return a.fitness_value > b.fitness_value;
}

int main() {
    srand(time(0));
    int population_number = 10;
    int count = 0;
    cout << "Insert your maximum weight: ";
    cin >> maximum_weight;
    vector <Solution> population;
    int repeated_maximum = 1;

    // Khoi tao quan the ban dau
    for(int i = 0; i < population_number; i++) {
        Solution A;
        A.random();
        if(i != 0)
            A.roulette_value += population[i - 1].roulette_value;
        population.push_back(A);
    }
    sort(population.begin(), population.end(), cmp);
    Solution maximum = population[0];
    cout << "Generation " << count++ << ": " << maximum.Genome << endl;

    while(repeated_maximum < best_solution_limit) {
        int accumulated_fitness = population[population_number - 1].roulette_value;
        vector<Solution> new_population;

        //thu tuc chon loc
        for(int i = 0; i < population_number; i++) {
            int roulette = rand() % accumulated_fitness + 1;
            int parents;
            for(int i = 0; i < population_number - 1; i++)
                if(population[i].roulette_value >= roulette) {
                    parents = i;
                    break;
                }
            Solution A = population[parents];
            new_population.push_back(A);
        }
        // neu quan the con khong du so luong thi bo sung bang ca the o quan the bo me
        while(new_population.size() < population_number)
            new_population.push_back(population[new_population.size()]);

        //thu tuc tuong giao cheo
        for(int i = 0; i < population_number; i+= 2)
            cross_over_function(new_population[i], new_population[i + 1]);

        //thu tuc bien di
        for(int i = 0; i < population_number; i++) {
            int r = rand() % 100 + 1;
            if(r < mutation_limit)
                mutation_function(new_population[i]);
        }

        //Tron lan 2 quan the
        for(int i = 0; i < population_number; i++)
            population.push_back(new_population[i]);
        for(int i = 0; i < population_number * 2; i++)
            population[i].fitness_value = population[i].fitness_function();

        //Sap xep lai quan the theo do tuong thich
        sort(population.begin(), population.end(), cmp);

        //loai bo bot cac ca the thich nghi yeu de quan the tro lai so luong n
        for(int i = 0; i < population_number; i++)
            population.pop_back();
        for(int i = 0; i < population_number; i++) {
            population[i].roulette_value = population[i].fitness_value;
            if(i != 0)
                population[i].roulette_value += population[i - 1].roulette_value;
        }

        //Tim ra loi giai tot nhat cua the he
        if(maximum.Genome != population[0].Genome) {
            maximum = population[0];
            repeated_maximum = 1;
        }
        else
            repeated_maximum++;
        cout << "Generation " << count++ << ": " << maximum.Genome << " with the fitness value of " << population[0].fitness_value << endl;
    }
    if(maximum.fitness_value == 0)
        cout << "No solution";
    else {
        cout << "\n##Cac vat dung co the mang theo lan luot la: ";
        for(int i = 0; i < number_of_variable; i++)
            if(maximum.Genome[i] == '1')
                cout << stuff[i].name << " ";
    }
}

