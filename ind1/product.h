#pragma once
#include <iostream>
#include <string>
using namespace std;
class stock;
class product
{

private:
	string name_product;
	size_t quantity;
	size_t price;
public:
	product(string name_product="", size_t quantity=0, size_t price=0) : name_product(name_product), quantity(quantity), price(price) {};
	string get_name_product()const { return name_product; }
	size_t get_quantity()const { return quantity; }
	size_t get_price()const { return price; }
	void set_name_product(string a) { name_product=a; }
	void set_quantity(size_t a) { quantity=a; }
	void set_price(size_t a) { price=a; }
	void print_all() { cout << name_product << " " << quantity << price << endl; }
	void set_all(string a, size_t b, size_t c) { name_product = a; quantity = b; price=c;}
	friend ostream &operator<<(std::ostream &os, const product &p);
	friend istream &operator>>(std::istream &is, product &p);
};

class stock
{
private:
	string name;//èìÿ ñêëàäà
	size_t size;//ñêîëüêî òàì õðîíèòüñÿ äîáðà
	product *product_in_stok;//ñàìî äîáðî 
public:
	stock(string name="", size_t size=1) :name(name), size(size)
	{
		product_in_stok = new product[size];
		for (int i = 0; i < size; ++i) product_in_stok[i];
	}

	stock(string name, size_t size, product *product_in_stok1) :name(name), size(size) 
	{
		
		product_in_stok = new product[size];
		for (int i = 0; i < size; ++i)
			product_in_stok[i] = product_in_stok1[i];
	}

	stock(const stock & d) :name(d.name), size(d.size)
	{
		product_in_stok = new product[size];
		for (int i = 0; i < size; ++i)
			product_in_stok[i] = d.product_in_stok[i];
	}

	~stock()
	{
		size=0;
		delete[] product_in_stok;
	}
	string get_name() { return name; }
	size_t get_size() { return size; }
	product operator[](int index) const { return product_in_stok[index]; }
	product &operator[](int index)  { return product_in_stok[index]; }
	string get_max_price()
	{
		int max = product_in_stok[0].get_price(), number=0;
		for (int i = 1; i < size; ++i)
		{
			if (product_in_stok[i].get_price() > max)
			{
				max = product_in_stok[0].get_price();
				number = i;
			}
		}
		return product_in_stok[number].get_name_product();
	}
	bool chek(string name)
	{
		for (int i = 0; i < size; ++i)
			if (product_in_stok[i].get_name_product() == name) return true;
		return false;
	}
	
	friend ostream &operator<<(std::ostream &os, stock a)
	{
		os << a.name << a.size;
		for (int i = 0; i < a.size; ++i) os << a.product_in_stok[i];
		return os;
	}

	friend  istream&operator>>(std::istream &is, stock &a)
	{
		is >> a.name >> a.size;
		delete[]a.product_in_stok;
		a.product_in_stok = new product[a.size];
		for (int i = 0; i < a.size; ++i) is >> a.product_in_stok[i];
		return is;
	}

	bool operator==(const stock &a)
	{
		return size == a.size;
	}
	bool operator<(const stock &a)
	{
		return size < a.size;
	}
	bool operator>(const stock &a)
	{
		return size > a.size;
	}

	stock operator=(const stock & d)
	{
		size = d.size;
		name = d.name;
		if (product_in_stok) delete[] product_in_stok;
		product_in_stok = new product[size];
		for (int i = 0; i < size; ++i)
			product_in_stok[i] = d.product_in_stok[i];
		return *this;
	}
	friend stock all_sozd();
};

inline ostream & operator<<(std::ostream & os, const product & p)
{
	os << p.get_name_product() << p.get_price() << p.get_quantity();
	return os;
}

inline istream & operator>>(std::istream & is, product & p)
{
	
	is >> p.name_product >> p.quantity >> p.price;
	return is;
}

stock all_sozd()
{
	string name;
	size_t size, size1;
	cout << "Ââèäèòå èìÿ ñêëàäà ";
	cin >> name;
	cout << " ââèäèòå êîëè÷åñòâî òîâàðà ";
	cin >> size;
	cout << endl;
	stock all(name, size);
	for (int i = 0; i < size; ++i)
	{
		cout << "Ââèäèòå èìÿ òîâàðà, êîëè÷åñòâî, ÷åíó ";
		cin >> name >> size >> size1;
		all.product_in_stok[i].set_all(name, size, size1);
	}
	return all;
}

