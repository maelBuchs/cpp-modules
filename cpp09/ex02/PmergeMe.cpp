#include "PmergeMe.hpp"
#include <algorithm>
#include <utility>
#include <vector>

#include <string>

#include <iostream>
#include <string>

static int stringToInt(std::string str) {
    int                result = 0;
    unsigned long long i = 0;

    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') // Vérification si c'est un chiffre
            throw PmergeMe::InvalidInput();
        result = result * 10 + (str[i] - '0');
        i++;
    }
    if (result != static_cast<int>(result))
        throw PmergeMe::InvalidInput();

    return result;
}

std::ostream &operator<<(std::ostream &os, const PmergeMe &pm) {

    std::deque<int>  deque = pm.getDequeData();
    std::vector<int> vector = pm.getVectorData();

    os << "deque: ";
    for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++) {
        os << *it << " ";
    }
    os << std::endl;

    os << "vector: ";
    for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++) {
        os << *it << " ";
    }
    os << std::endl;

    return os;
}

const char *PmergeMe::InvalidInput::what() const throw() { return "Error: Invalid input !"; }

PmergeMe::PmergeMe(char **input) {
    parseInput(input);
    // throw InvalidInput();
}

static bool isNumber(const std::string &str) {
    for (size_t i = 0; i < str.size(); i++) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

void PmergeMe::parseInput(char **input) {
    for (int i = 0; input[i]; i++) {
        std::cout << input[i] << std::endl;
        if (!isNumber(input[i]))
            throw InvalidInput();
        int tmp = stringToInt(input[i]);
        _dequeData.push_back(tmp);
        _vectorData.push_back(tmp);
    }
    std::cout << *this << std::endl;
}

PmergeMe::~PmergeMe() {}

//create a function to print an int vector
void printVector(std::vector<int> vec)
{
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}


void PmergeMe::processData() { vectorFordJhonson(_vectorData, 0); }

std::vector<int> PmergeMe::vectorFordJhonson(std::vector<int> list, int depth)
{
	std::cout << "new recursion " << depth << std::endl;
	int last = -1;
	if(list.size() <= 1)
		return list;

	pairVec pairs;
	for(unsigned long i = 0; i < list.size() - 1; i+=2)
	{
		if (i+1 < list.size())
			pairs.push_back(std::pair<int,int>(std::max(list[i], list[i+1]), std::min(list[i], list[i+1])));
		else
			last = list[i];
	}

	std::vector<int> maxList, minList;

	for(pairVec::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		maxList.push_back(it->first);
		if(it->second)
			minList.push_back(it->second);
	}
	if(last != -1)
		maxList.push_back(last);

	
	std::cout << "MAxlist " << depth << std::endl;
	printVector(maxList);
	std::cout << "Minlist " << depth << std::endl;
	printVector(minList);

	std::vector<int> sortedMax = vectorFordJhonson(maxList, depth + 1);
	std::cout << "sortedMAxlist " << depth << std::endl;

	printVector(sortedMax);
	return sortedMax;
}

/*

function ford_johnson_sort(list):
    if taille(list) <= 1:
        return list

    # 1. Former des paires
    pairs = []
    for i de 0 à taille(list) - 1 par 2:
        if i + 1 < taille(list):
            pairs.append(trier([list[i], list[i+1]]))  # Trier chaque paire
        else:
            pairs.append([list[i]])  # Élément seul s'il y a un nombre impair d'éléments

    # 2. Séparer les petits et les grands
    petits = [pair[0] for pair in pairs]
    grands = [pair[1] for pair in pairs si taille(pair) == 2]

    # 3. Trier récursivement les grands
    grands_tries = ford_johnson_sort(grands)

    # 4. Insérer les petits dans les grands triés
    liste_finale = insérer_ordre(petits, grands_tries)

    return liste_finale
        */