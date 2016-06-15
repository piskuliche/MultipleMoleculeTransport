#pragma once
#ifndef read_file_H
#define read_file_H
#include "main.h"

void read_file(int& number_of_species, vector<int>& number_of_atoms, vector<atom>& molecule, string& filename, int& current_time, int& time_dump_freq, int& start_time, int& total_atoms, vector<int>& s_loc);


#endif