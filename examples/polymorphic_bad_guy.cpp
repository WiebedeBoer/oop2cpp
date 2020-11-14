// polymorphic_bad_guy.cpp
// Compile with: g++ polymorphic_bad_guy.cpp -o polymorphic_bad_guy

#include <iostream>

using namespace std;

class Enemy
{
public:
    Enemy(int damage = 10);
    void virtual Attack() const;
    
protected:
    int m_Damage;
};

Enemy::Enemy(int damage)
{
    m_Damage = damage;
}

void Enemy::Attack() const
{
    cout << "An enemy attacks and inflicts " << m_Damage << " damage points.";
}  

class Boss : public Enemy
{
public:
    Boss(int multiplier = 3); 
    void virtual Attack() const;
    
protected:
    int m_Multiplier; 
};

Boss::Boss(int multiplier)
{
    m_Multiplier = multiplier;
}

void Boss::Attack() const
{
    cout << "A boss attacks and inflicts " << m_Damage * m_Multiplier
         << " damage points.";
} 

int main()
{
    cout << "Calling Attack() on Boss object through pointer to Enemy:\n";
    Enemy *pBadGuy = new Boss();
    pBadGuy->Attack();
   
    cout << "\n\nDeleting pointer to Enemy:\n";
    delete pBadGuy;
    pBadGuy = 0;
   
    return 0;
}

