int main()
{
	cout<<endl<<"\n\t\t-------------------------------";
	cout<<endl<<"\n\t\t| S P E L L   C H E C K K E R |";
	cout<<endl<<"\n\t\t-------------------------------";
	cout<<endl<<"\n\n\t\tATIF ALI  (21K-3340)\n\n\t\tBILAL AHMED  (21K-4864)\n\n\t\tMUHAMMAD  (21K-3192)";

    loadingfunction();
    
	BST ob;
	Node *root = NULL;
	ifstream inputFile("words.txt");
	
	string str="";
	int counter=0, option=0;
	while(!inputFile.eof())
	{
		inputFile >> str;
		root = ob.insert(root, str);
	}

	do{
		system("cls");
		cout<<"\n\n\t\tENTER 1 FOR WORD CORRECTION\n\t\tENTER 2 FOR PARAGRAPH CORRECTION\n\t\tENTER 0 TO EXIT"<<endl;
		cout<<" \n\n\t\t YOUR OPTION : ";
		cin>>option;
		
		if(option==0)
			break;
			
		if(option==1){
			
				string input,line;
        		int len,flen,correct=0;
        		cout<<"\n\t\tENTER THE WORD : "; 
        		fflush(stdin);
				getline(cin,input);
        
				len = input.length();
        
				for (int i=0; i < len; i++)
            		input[i] = tolower(input[i]);
		
				if(ob.searchAvltree(root,input)==true){
					cout<<"\n\t\tTHE SPELLING IS CORRECT !"<<endl;
				}
				else{
					int missing = 0, extra = 0, mixed = 0, incorrect = 0, exchanged = 0;
                	cout<<endl<<"\n\t\tSPELLING IS WRONG . POSSIBLE RIGHT SPELLINGS ARE GIVEN BELOW :  "<<endl<<endl;
                
					missing = missingCharacter(input, root);
					extra = extraCharacter(input, root);
                	mixed = mixedExtraMissing(input, root);
                	incorrect = incorrectArrangement(input,root);
                	exchanged = exchangedCharacters(input,root);
                
					if (missing == 0 && mixed == 0 && extra == 0 && incorrect == 0 && exchanged == 0)
                	{
                    	cout<<endl<<"\n\t\tNO SUCH WORD EXIST"<<endl;
                	}
				}
				cout << endl << endl << "\t\t";
				system("pause");
			}
				
			
			else if(option==2){
				cout << "\n\t\tENTER YOUR PARAGRAPH : ";
				fflush(stdin);
				getline(cin, str);
	
				stringstream ss(str);
				string temp;
				string corrected="";
				LinkedList<CorrectedWords> CWL;
	
				while(getline(ss, temp, ' '))
				{
					system("cls");
					LinkedList<string> LL;
					bool full_stop_present = 0;
		
					if(temp[temp.length()-1] == '.')
					{
						temp.pop_back();
						full_stop_present=1;
					}
		
					string check = CWL.searchMistake(temp);
					if(check != "N/A")
					{
						temp = check;
						if(full_stop_present == 1)
							temp.push_back('.');
						temp.push_back(' ');
						corrected = corrected + temp;
						continue;
					}
		
					CorrectedWords C;
					C.mistake = temp;
		
					spellchecker(temp, LL, root);
					cout <<"\n\t\tYOUR SENTENCE : "<< str << endl << endl;
					if(LL.head != NULL)
					{
						int choice=0;
						cout<<"\n\t\tYOUR MISTAKE : "<<temp;
						cout <<"\n\n\t\tDO YOU WANT TO IGNORE THE SPELLING MISTAKE ?:  (1 FOR YES, 0 FOR NO) ";
						cin >> choice;
						if(choice == 0)
						{
							int ans;
							int limit = LL.getLength();
						//	cout<<"\n\t\t";
							cout << endl << "\n\t\tTHESE ARE THE SUGGESTED MISTAKES ;\n";
							LL.print();
							 cout<<"\n\n\t\tENTER FOR WHICH NUMBER YOU WANT TO REPLACE: ";
							while(1)
							{
								cin >> ans;
								if (ans >= 1 && ans <= limit)
									break;
								cout << "/n/t/tINVALID SELECTION ! CHOOSE AGAIN ." << endl;
							}
							temp = LL.searchWord(ans);
							C.correction = temp;
							CWL.insert(C);
						}
					}
					else
					{
						if(ob.searchAvltree(root, temp) == false)
						{
							int ans2=0;
							cout << endl << temp << "\n\t\tDOESNOT EXIST. DO YOU WANT TO IGNORE OR REMOVE THIS WORD ? (1 FOR IGNORE, 0 FOR REMOVE) ";
							cin >> ans2;
							if(ans2 == 0)
								continue;
						}
					}
					if(full_stop_present == 1)
						temp.push_back('.');
					temp.push_back(' ');
					corrected = corrected + temp;
				}
	
				cout << "\n\t\tTHE CORRECTED PARA IS : "  << corrected<<endl;
	
				if(CWL.head != NULL)
				{
					cout << "\n\n\t\tYOUR MISTAKE HISTORY IS AS FOLLOWS : \n\n";
					cout << "\t\tMISTAKES\t:\tCORRECTIONS " << endl;
					CWL.print();
					cout << endl << endl << "\t\t";
					system("pause");
				}
			}
			else{
				cout<<"\n\t\tENTER CORRECT OPTION : "<<endl;
			}
		//	system("cls");	
	}while(option!=0);

    return 0;
}