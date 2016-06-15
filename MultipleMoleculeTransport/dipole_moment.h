#pragma once
#ifndef dipole_H
#define dipole_H
#include "main.h"

void calculate_dipole_moment(vector<int>& number_of_atoms, vector<int>& atoms_per_molecule, vector<atom>& molecule, int& current_time, int& time_origin, vector<int>& type, int& number_of_species, vector<int>& s_loc);

#endif