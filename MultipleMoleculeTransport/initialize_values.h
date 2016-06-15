#pragma once
#ifndef initialize_values_H
#define initialize_values_H
#include "main.h"

void initialize_values(vector<int>& number_of_molecules, vector<int>& number_of_atoms, vector<int>& atoms_per_molecule, vector<atom>& molecule, vector<reorientation>& reor, vector<diffusion>& diff, int& number_of_species, int& start_time, int& end_time, int& time_dump_freq, vector<int>& s_loc);

#endif