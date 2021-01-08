#include "main.hpp"

int main() {
    print_line();
    cout << endl << "main_bfs();" << endl << endl;
    print_line();
	main_bfs();

    print_line();
	cout << endl << "main_dfs();" << endl << endl;
	print_line();
	main_dfs();

	print_line();
	cout << endl << "main_floyd();" << endl << endl;
	print_line();
	main_floyd();

    print_line();
	cout << endl << "main_kruskal();" << endl << endl;
	print_line();
	main_kruskal();

    print_line();
	cout << endl << "main_prim();" << endl << endl;
	print_line();
	main_prim();

	print_line();
	cout << endl << "main_pruefer();" << endl << endl;
	print_line();
	main_pruefer();

	return 0;
}

void print_line()
{
    cout << endl;
    for (int i = 0; i < 16; i++)
    {
        cout << " =";
    }
    cout << endl << endl;
}
