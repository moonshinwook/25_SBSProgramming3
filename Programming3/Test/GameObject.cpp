#include "GameObject.h"

GameObject::GameObject(int hp, int atk, int def, int debuff)
    : HP(hp), ATK(atk), DEFENSE(def), DEBUFF(0) 
{
}

GameObject::GameObject() : GameObject(100, 10, 0, 0) // ±‚∫ª Ω∫≈»
{
}
