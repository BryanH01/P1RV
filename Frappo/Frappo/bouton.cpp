#include "bouton.h"

bool isE(int x, int y) {
	if ((250 < x) && (x < 550) && (450 < y) && (y < 550)) {
		return true;
	}
	else {
		return false;
	}
}

bool isT(int x, int y) {
	if ((1050 < x) && (x < 1350) && (450 < y) && (y < 550)) {
		return true;
	}
	else {
		return false;
	}
}

bool isF(int x, int y) {
	if ((500 < x < 600) && (300 < y < 400)) {
		return true;
	}
	else {
		return false;
	}
}

bool isS(int x, int y) {
	if ((1300 < x) && (x < 1500) && (50 < y) && (y < 150)) {
		return true;
	}
	else {
		return false;
	}
}