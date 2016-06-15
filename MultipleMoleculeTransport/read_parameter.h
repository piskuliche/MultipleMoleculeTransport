#pragma once
#ifndef read_parameter_H
#define read_parameter_H
#include "main.h"

void read_parameter(vector<int>& number_of_atoms, vector<int>& atoms_per_molecule, vector<int>& number_of_molecules, vector<int>& type, int& number_of_species, int& box_side, int& dump_freq, int& start_time, int& end_time, int& n_corr, string& filename, vector<double>& mass, int& bin_length, int& calc_every, int& dt, int& lines, vector<atom>& molecule, int& total_atoms, vector<int>& s_loc);

#endif