#include "squirrel.h"
#include "druid.h"
#include "orc.h"

Druid::Druid(int x, int y) : NPC(DruidType, x, y) {}
Druid::Druid(std::istream &is) : NPC(DruidType, is) {}

void Druid::print()
{
    std::cout << *this;
}

void Druid::save(std::ostream &os)
{
    os << DruidType << std::endl;
    NPC::save(os);
}

bool Druid::is_druid() const
{
    return true;
}

bool Druid::fight(std::shared_ptr<Squirrel> other)
{
    fight_notify(other, true);
    return true;
}

bool Druid::fight(std::shared_ptr<Druid> other)
{
    fight_notify(other, false);
    return false;
}

bool Druid::fight(std::shared_ptr<Orc> other)
{
    fight_notify(other, false);
    return false;
}

std::ostream &operator<<(std::ostream &os, Druid &druid)
{
    os << "Druid: " << *static_cast<NPC *>(&druid) << std::endl;
    return os;
}