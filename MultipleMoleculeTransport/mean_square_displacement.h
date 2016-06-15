#pragma once
#ifndef mean_square_displacement_H
#define mean_square_displacement_H
#include "main.h"

void calculate_mean_square_displacement(bool& diff_flag, vector<int>& number_of_atoms, vector<int>& atoms_per_molecule, vector<int>& number_of_molecules, vector<atom>& molecule, int& current_time, int& time_origin, int& dt, vector<diffusion>& diff, string& output_string, int& number_of_species, vector<int>& s_loc);

#endif