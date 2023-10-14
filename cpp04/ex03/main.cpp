#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main() {
  // Test default constructors
  IMateriaSource* src = new MateriaSource();
  ICharacter* me = new Character("me");
  ICharacter* bob = new Character("bob");

  // Test learning and creating materia
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  AMateria* tmpIce = src->createMateria("ice");
  AMateria* tmpCure = src->createMateria("cure");

  // Test equipping and using materia
  me->equip(tmpIce);
  me->use(0, *bob);

  me->equip(tmpCure);
  me->use(1, *bob);

  // Test copy constructor
  ICharacter* copyOfMe = new Character(*static_cast<Character*>(me));
  std::cout << copyOfMe->getName() << ": ";
  copyOfMe->use(0, *bob);
  std::cout << copyOfMe->getName() << ": ";
  copyOfMe->use(1, *bob);

  // Test assignment operator
  ICharacter* assignee = new Character("assignee");
  *static_cast<Character*>(assignee) = *static_cast<Character*>(me);
  std::cout << assignee->getName() << ": ";
  assignee->use(0, *bob);
  std::cout << assignee->getName() << ": ";
  assignee->use(1, *bob);

  // Cleanup and test destructor
  delete assignee;
  delete copyOfMe;
  delete bob;
  delete me;
  delete src;

  return 0;
}
