#pragma once

#include <iostream>

using namespace std;

class Person {
	long m_id;
	string m_name;

public:
	Person(long id = 0, string name = "none") { m_id = id; m_name = name; }

	const long& get_id() const { return this->m_id; }
	const string& get_name() const { return this->m_name; }

	void set_id(long newID) { this->m_id = newID; }
	void set_name(string newName) { this->m_name = newName; }

	bool operator>(Person& p) const { return (this->m_id > p.m_id); }
	bool operator==(Person& p) const { return (this->m_id == p.m_id); }
};