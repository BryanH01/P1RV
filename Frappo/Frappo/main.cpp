#include "intro.h"
#include "Interface.h"
#include "Frappo.h"
#include "FileHandler.h"
#include "fini.h"

#include <thread>
#include <future>

int main() {
	
	int mode = 0;
	string nom;
	while (true) {
		switch (mode)
		{
			case 0 : 
				mode = intro();
				break;
			case 1:
				Enregistrement();
				mode = 3;
				break;
			case 3:
				finiE();
				mode = 0;
				break;
			case 2:
				nom = Identification();
				mode = 4;
				break;
			case 4:
				finiI(nom);
				mode = 0;
				break;
			default:
				break;
		}
	}

	return 0;
}