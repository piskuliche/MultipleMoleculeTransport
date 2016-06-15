#pragma once
#ifndef reorientation_correlation_H
#define reorientation_correlation_H
#include "main.h"

void calculate_reorientation_correlation_function(bool reorient_flag, vector<int>& number_of_atoms, vector<int>& number_of_molecules, vector<int>& atoms_per_molecule, vector<atom>& molecule, int& current_time, int& time_origin, int& dt, vector<reorientation>& reor, string& output_string, int& number_of_species, vector<int>& s_loc);

#endif