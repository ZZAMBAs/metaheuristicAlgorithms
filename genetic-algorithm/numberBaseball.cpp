/*
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <unordered_set>

using namespace std;

// 개체를 나타내는 클래스
class Individual {
public:
    vector<int> genes; // 개체의 유전자 (4개의 수)
    int fitness; // 개체의 적합도 (맞춘 숫자의 개수)

    // 유전자를 무작위로 초기화
    void initializeGenes() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, 100000);
        for (int & gene : genes) {
            gene = dis(gen);
        }
    }

    // 적합도를 계산
    void calculateFitness(const vector<int>& target) {
        fitness = 0;
        for (int i = 0; i < target.size(); ++i) {
            for (int j = 0; j < genes.size(); j++) {
                if (target[i] == this->genes[j]) {
                    fitness += i == j ? 10 : 1;
                }
            }
        }

    }

    // 개체를 출력
    void print() {
        for (int gene : genes) {
            cout << gene << " ";
        }
        cout << " (" << fitness / 10 << " 스트라이크, " << fitness % 10 << " 볼)" << std::endl;
    }
};

// 개체를 비교하는 함수 (적합도를 기준으로 내림차순 정렬)
bool compareIndividuals(const Individual& ind1, const Individual& ind2) {
    return ind1.fitness > ind2.fitness;
}

// 유전 알고리즘을 실행하는 함수
void runGeneticAlgorithm(const vector<int>& target, int populationSize, double mutationRate, int maxGenerations) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 100000);

    vector<Individual> population(populationSize);

    // 초기 개체 생성 및 적합도 계산
    for (int i = 0; i < populationSize; ++i) {
        population[i].genes.resize(target.size());
        population[i].initializeGenes();
        population[i].calculateFitness(target);
    }

    int generation = 0; // 현재 세대
    while (generation < maxGenerations) {
        // 개체를 적합도 순으로 정렬
        sort(population.begin(), population.end(), compareIndividuals);

        // 현재 세대의 정보 출력
        cout << generation << "세대" << " - 최적 해: ";
        population[0].print();

        // 종료 조건 확인
        if (population[0].fitness == target.size() * 10) {
            break; // 최적 해를 찾았으므로 종료
        }

        // 다음 세대 개체 생성
        vector<Individual> nextGeneration(populationSize);
        // 엘리트 개체는 바로 다음 세대로 복제
        for (int i = 0; i < populationSize / 2; ++i) {
            nextGeneration[i] = population[i];
        }

        // 나머지 개체들은 교차와 돌연변이를 적용하여 생성
        for (int i = populationSize / 2; i < populationSize; ++i) {
            nextGeneration[i].genes.resize(4);
            // 두 개체를 선택하여 교차 수행
            int parent1Idx = gen() % (populationSize / 2);
            int parent2Idx = gen() % (populationSize / 2);
            for (int j = 0; j < target.size(); ++j) {
                // 교차 시 두 개체의 유전자를 섞어줌
                if (dis(gen) % 2 == 0) {
                    nextGeneration[i].genes[j] = population[parent1Idx].genes[j];
                } else {
                    nextGeneration[i].genes[j] = population[parent2Idx].genes[j];
                }
            }

            // 돌연변이 적용
            for (int j = 0; j < target.size(); ++j) {
                if (static_cast<double>(dis(gen)) / dis.max() < mutationRate) {
                    nextGeneration[i].genes[j] = dis(gen);
                }
            }

            // 적합도 계산
            nextGeneration[i].calculateFitness(target);
        }

        // 다음 세대를 현재 세대로 업데이트
        population = nextGeneration;

        generation++;
    }

    // 최종 결과 출력
    cout << "최종 세대 - 최적 해: ";
    population[0].print();
}

int main() {
    unordered_set<int> visited;
    vector<int> target(4); // 목표 수
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 100000);
    for(auto &t : target) {
        int randomNum = dis(gen);
        while(visited.find(randomNum) != visited.end()){
            randomNum = dis(gen);
        }
        t = randomNum;
        visited.insert(t);
        cout << t << " ";
    }
    cout << " <-- 정답\n";

    int populationSize = 2000; // 개체 집단 크기(크기가 클수록 집단의 다양성이 좋아지지만 성능문제를 생각해야 한다.)
    double mutationRate = 0.15; // 돌연변이 비율 (높을수록 local optimum에 빠지지 않을 수 있지만 최적해를 찾기 어려울 수 있다. - 많은 시도를 필요로 할 수 있다.)
    int maxGenerations = 10000; // 최대 세대 수

    // local optimum에 빠지지 않기위해 돌연변이 수를 조정하거나 교배 방식을 다양하게 적용하자.

    runGeneticAlgorithm(target, populationSize, mutationRate, maxGenerations);

    return 0;
}*/
