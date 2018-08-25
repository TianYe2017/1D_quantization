#include "stdafx.h"
#include "hw2_p2_1.h"
#include <vector>
#include <string>
#include <iostream>  
#include <fstream> 


using namespace std;


void HW2_Problem_two_part_one(void) 
{
	string path1 = "E:\\MY_LOG\\669\\hw2\\input\\chem.256";
	string path2 = "E:\\MY_LOG\\669\\hw2\\input\\house.256";
	string path3 = "E:\\MY_LOG\\669\\hw2\\input\\moon.256";
	string path4 = "E:\\MY_LOG\\669\\hw2\\input\\couple.256";
	string path5 = "E:\\MY_LOG\\669\\hw2\\input\\f16.256";
	string path6 = "E:\\MY_LOG\\669\\hw2\\input\\elaine.256";

    vector<unsigned char> chem = ReadBinaryFile(path1);
	vector<unsigned char> house = ReadBinaryFile(path2);
	vector<unsigned char> moon = ReadBinaryFile(path3);
	vector<unsigned char> couple = ReadBinaryFile(path4);
	vector<unsigned char> f16 = ReadBinaryFile(path5);
	vector<unsigned char> elaine = ReadBinaryFile(path6);

	Quantization_1D* p = new Quantization_1D(4);
	p->Add_Train_Data(chem);
	p->Add_Train_Data(house);
	p->Add_Train_Data(moon);
	p->Init();
	for (int i = 0; i < 100; i++) 
	{   
		if (p->halt_sign != true) 
		{
			p->Update_Once();
			p->num_of_iter++;
			cout << "NUM_of_Iter: " << p->num_of_iter << endl;
		}
		else 
		{
			break;
		}	
	}

	vector<unsigned char> new_chem = p->Reconstruct_Image(chem);
	vector<unsigned char> new_house = p->Reconstruct_Image(house);
	vector<unsigned char> new_moon = p->Reconstruct_Image(moon);
	vector<unsigned char> new_couple = p->Reconstruct_Image(couple);
	vector<unsigned char> new_f16 = p->Reconstruct_Image(f16);
	vector<unsigned char> new_elaine = p->Reconstruct_Image(elaine);

	string P1 = "E:\\MY_LOG\\669\\hw2\\output\\P2_OUT\\new_chem.raw";
	string P2 = "E:\\MY_LOG\\669\\hw2\\output\\P2_OUT\\new_house.raw";
	string P3 = "E:\\MY_LOG\\669\\hw2\\output\\P2_OUT\\new_moon.raw";
	string P4 = "E:\\MY_LOG\\669\\hw2\\output\\P2_OUT\\new_couple.raw";
	string P5 = "E:\\MY_LOG\\669\\hw2\\output\\P2_OUT\\new_f16.raw";
	string P6 = "E:\\MY_LOG\\669\\hw2\\output\\P2_OUT\\new_elaine.raw";

	Write_Image_To_Dat(new_chem, P1);
	p->Computer_PSNR(new_chem, chem);
	Write_Image_To_Dat(new_house, P2);
	p->Computer_PSNR(new_house, house);
	Write_Image_To_Dat(new_moon, P3);
	p->Computer_PSNR(new_moon, moon);
	Write_Image_To_Dat(new_couple, P4);
	p->Computer_PSNR(new_couple, couple);
	Write_Image_To_Dat(new_f16, P5);
	p->Computer_PSNR(new_f16, f16);
	Write_Image_To_Dat(new_elaine, P6);
	p->Computer_PSNR(new_elaine, elaine);


	vector<unsigned char> new_chem1 = ReadBinaryFile("E:\\MY_LOG\\669\\hw2\\output\\P2_OUT\\new_chem.raw");
	vector<unsigned char> new_house1 = ReadBinaryFile("E:\\MY_LOG\\669\\hw2\\output\\P2_OUT\\new_house.raw");
	vector<unsigned char> new_moon1 = ReadBinaryFile("E:\\MY_LOG\\669\\hw2\\output\\P2_OUT\\new_moon.raw");
	vector<unsigned char> new_couple1 = ReadBinaryFile("E:\\MY_LOG\\669\\hw2\\output\\P2_OUT\\new_couple.raw");
	vector<unsigned char> new_f161 = ReadBinaryFile("E:\\MY_LOG\\669\\hw2\\output\\P2_OUT\\new_f16.raw");
	vector<unsigned char> new_elaine1 = ReadBinaryFile("E:\\MY_LOG\\669\\hw2\\output\\P2_OUT\\new_elaine.raw");

	cout << " sorting... 6 left " << endl;
	vector<data_pair> chem_pdf = Sort_Raw_Data(new_chem1);
	cout << " sorting... 5 left " << endl;
	vector<data_pair> house_pdf = Sort_Raw_Data(new_house1);
	cout << " sorting... 4 left " << endl;
	vector<data_pair> moon_pdf = Sort_Raw_Data(new_moon1);
	cout << " sorting... 3 left " << endl;
	vector<data_pair> couple_pdf = Sort_Raw_Data(new_couple1);
	cout << " sorting... 2 left " << endl;
	vector<data_pair> f16_pdf = Sort_Raw_Data(new_f161); 
	cout << " sorting... 1 left " << endl;
	vector<data_pair> elaine_pdf = Sort_Raw_Data(new_elaine1);

	double entropy_chem = Compute_Entropy(chem_pdf);
	double entropy_house = Compute_Entropy(house_pdf);
	double entropy_moon = Compute_Entropy(moon_pdf);
	double entropy_couple = Compute_Entropy(couple_pdf);
	double entropy_f16 = Compute_Entropy(f16_pdf);
	double entropy_elaine = Compute_Entropy(elaine_pdf);

	cout << " entropy_chem: " << entropy_chem << endl;
	cout << " entropy_house: " << entropy_house << endl;
	cout << " entropy_moon: " << entropy_moon << endl;
	cout << " entropy_couple: " << entropy_couple << endl;
	cout << " entropy_f16: " << entropy_f16 << endl;
	cout << " entropy_elaine: " << entropy_elaine << endl;








}
