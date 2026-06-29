#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Unicorn
{
private:
    string name;
    bool alive;

    static vector<string> taken_names;

    static bool name_taken(string check_name)
    {
        for (int i = 0; i < taken_names.size(); i++)
        {
            if (taken_names[i] == check_name)
            {
                return true;
            }
        }

        return false;
    }

    static void add_name(string new_name)
    {
        taken_names.push_back(new_name);
    }

    static void remove_name(string old_name)
    {
        for (int i = 0; i < taken_names.size(); i++)
        {
            if (taken_names[i] == old_name)
            {
                taken_names.erase(taken_names.begin() + i);
                return;
            }
        }
    }

public:
    Unicorn(string new_name)
    {
        if (name_taken(new_name))
        {
            cout << "Error: The name " << new_name << " is already taken." << endl;
            name = "";
            alive = false;
        }
        else
        {
            name = new_name;
            alive = true;
            add_name(name);

            cout << "A unicorn named " << name << " was created." << endl;
        }
    }

    ~Unicorn()
    {
        if (alive)
        {
            remove_name(name);
            cout << "The name " << name << " is now free." << endl;
        }
    }

    string get_name() const
    {
        return name;
    }

    bool is_alive() const
    {
        return alive;
    }

    void print() const
    {
        if (alive)
        {
            cout << "Unicorn name: " << name << endl;
        }
        else
        {
            cout << "This unicorn was not created because the name was already taken." << endl;
        }
    }
};

vector<string> Unicorn::taken_names;

int main()
{
    cout << "Creating unicorns:" << endl;

    Unicorn first("Starlight");
    Unicorn second("Moonbeam");
    Unicorn third("Starlight");

    cout << endl;

    first.print();
    second.print();
    third.print();

    cout << endl;
    cout << "Testing name reuse after a unicorn is destroyed:" << endl;

    {
        Unicorn temporary("Rainbow");
        temporary.print();
    }

    Unicorn new_unicorn("Rainbow");
    new_unicorn.print();

    cout << endl;
    cout << "Program ending." << endl;

    return 0;
}