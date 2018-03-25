#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <time.h>
#include <Windows.h>
#include <string>
#include <algorithm>
#include "Header.h"

using namespace std;
unsigned short int nz;

int i, j;

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, ".1251");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (true)
	{
		cout << "Введите номер задания (0 - что бы выйти) : ";
		cin >> nz;
		cin.get();

		if (nz == 0)
		{
			break;
			system("exit");
		}

		else if (nz == 1)
		{
			system("cls");
			/*1.Дана строка из нескольких слов. Слова отделяются друг от друга пробелами или запятыми. Вывести слова, начинающиеся и заканчивающиеся одной и той же буквой.*/
			char str[256];
			cout << "Введите строку: ";
			gets_s(str);
			char seps[] = ", ";
			char *token;
			int str_count = 0;
			char* currentStr = 0;
			int count_equal = 0;
			token = strtok(str, seps);
			while (token != NULL)
			{
				cout << token << endl;
				if (token[0] == token[strlen(token) - 1])
				{
					cout << count_equal + 1 << " найденное слово - " << token << endl;
					count_equal++;
				}
				token = strtok(NULL, seps);
			}

			cout << "Найдено " << count_equal << " слов(а)" << endl;
		}

		else if (nz == 2)
		{
			/*2.	Дан массив символов, в котором встречаются структуры <i> и </i>. Заменить каждое вхождение <i> на </i>, а каждое вхождение </i> на <#>.
			Замечание: в программе следует учесть, что буква i может быть, как строчной, так и прописной*/
			system("cls");
			char * a = "<i>", *b = "</#>";
			char * m = createDunamicChar(150);

			strcpy(m, "<i><body><hr><ul><i> массив символов</i><i>встречаются структуры</i><i>каждое вхождение</i><i>как строчной</i></ul><hr></body>");
			printf("\n Before replace : %s \n", m);
			replacestr(m, a, b);
			printf("\n After replace : %s \n", m);
		}

		else if (nz == 3)
		{
			/*3.Дан массив символов, содержащий число в двоичной системе счисления. Проверить правильность ввода этого числа (в его записи должны быть только символы 0 и 1).
			Если число введено неверно, повторить ввод. При правильном вводе перевести число в десятичную систему счисления*/
			system("cls");
			string bin;
			do
			{
				cout << "Vvedite chislo v dvoichnoy sisteme: ";
				cin >> bin;
			} while ([](const string &str) -> bool
			{
				for (const auto &c : str)
					if (c != '0' && c != '1')
						return true;
				return false;
			}	(bin));
			cout << stoll(bin, 0, 2) << endl;
		}

		else if (nz == 4)
		{
			system("cls");
			/*4.Дан массив символов, содержащий текст. Определить длину содержащейся в нем максимальной серии символов, отличных от букв.*/
			static char str[256] = "abc38494defghi4959384759387i0874598398579438759438435\0";
			printf("string = %s\n", str);

			char output[256] = "\0";
			int max_len = 0, pos = max_len;
			for (int i = 0; str[i] != '\0'; i++)
				if (isdigit(str[i]))
				{
					int l = i, n = 0; char digits[256] = "\0";
					while (isdigit(str[i]) && str[i] != '\0')
						digits[n++] = str[i++];

					if (abs(l - i) > max_len || max_len == 0)
					{
						strcpy(output, digits);
						max_len = abs(l - i);
						pos = l;
					}
				}

			printf("output = %s pos = %d len = %d\n", output, pos, max_len);
		}

		else if (nz == 5)
		{
			/*5. Дан массив символов. Преобразовать его, заменив точками все двоеточия (:), встречающиеся среди первой половины символов,
			и заменив точками все восклицательные знаки, встречающиеся среди символов, стоящих во второй половине исходного массива*/
			system("cls");
			string text = "ggsagsg:Gsdgsgsg:gsdgGEWA:";
			replace(text.begin(), text.end(), ':', '.');
			cout << text << endl;
		}

		else if (nz == 6)
		{
			/*6.Дан массив символов. Указать те слова, которые содержат хотя бы одну букву k*/
			system("cls");
			char *str = "Дан массив сkимволов . Указатьk те слkова";
			char * word = (char*)calloc(50, sizeof(char));
			int n = 0, kon = 0, ws = 0;

			while (kon < strlen(str))
			{
				while (str[kon] != ' '&&str[kon] != ',')
				{
					if (kon != strlen(str))
						kon++;
					else break;
				}

				for (int i = n;i < kon;i++)
				{
					word[ws] = str[i];
					ws++;
				}

				word[ws] = '\0';
				for (int i = 0;i < strlen(word);i++)
				{
					if (word[i] == 'k')
					{
						printf("%s \n", word);
						break;
					}
				}
				n = kon + 1;
				if (str[kon] != ' ' || str[kon] != ',') kon++;
				ws = 0;
			}
		}

		else if (nz == 7)
		{
			/*7.Дан массив символов, содержащий текст. В строке между словами вставить вместо пробела запятую и пробел*/
			system("cls");
			/*char str[100] = "Всем доброго дня";

			cout << str << endl;
			change(str);
			cout << str << endl;*/
			string s, r;
			char c;
			s = "Дан массив символов содержащий текст";
			for (int i = 0; (c = s[i]) != '\0'; i++)
			{
				if (c == ' ')
					r += ',';
				r += c;
			}

			cout << s << endl;
			cout << r << endl;

		}

		else if (nz == 8)
		{
			/*8.Дан массив символов, содержащий текст, заканчивающийся точкой. Вывести на экран слова, содержащие три буквы.*/
			system("cls");
			char * s=NULL;
			char slova[50];
			int n=0, nsl, ksl, kol, i;
			s = (char*)calloc(50, sizeof(char));
			printf("Vvedite stroku\n");
			fgets(s,50,stdin);
			s = ' ' + s + ' ';
			n = strlen(s);
			printf("%s\n",s);
		}


		else
		{
			printf("Такого задания нет!");
			exit(EXIT_FAILURE);
		}
	}
}
