#include <iostream>
#include <locale.h>
#include <Windows.h>
#include <time.h>
#include <fstream>
#include "Character.h"
#include "Equipment.h"
#include "Pet.h"
#include "Helpers.h"
#include "Game.h"
#include "SaveTemp.cpp"
#include "Message.cpp"
#include "Mob.h"
using namespace std;

int hiscoreOku(), petsecme(), KayitNo = 0, kritik, dodge;
void savemenu(), karakterstatu(), zorluk(), oyunmenu(), magaza(), banka(), zindanlar(), orumcekzindani(), maymunzindani(), level(), petlvl(), statugelistir(), karaktersecme(), envanter(), save(int gelenKayitNo), dosyakayitOku(int gelenKayitSecim), KayitSil(int silinecekKayit);

Game game(0, 0, 0);
Character character(0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
Equipment firstAid(0, 0, 100);
Equipment grenade(0, 0, 150);
Pet pet(1, 0, 0);

Helpers helper;
Message message;

void hizala(int satir, int tab) {
	for (int i = 0; i < satir; i++)
		cout << "\n";
	for (int j = 0; j < tab; j++)
		cout << "\t";
}
void harfOku(string metin, int uzunluk) {
	for (int i = 0; i < uzunluk; i++) {
		cout << metin[i];
		Sleep(100);
	}
}
void hosgeldiniz() {
	system("COLOR 3E");
	for (int i = 0; i < 5; i++) {
		hizala(0, 6);
		for (int j = 0; j < 9; j++) {
			if (i == 2 && j == 0)
				cout << "* Dungeon Beast *";
			(i == 0 || i == 4) ? (cout << "* ") : (cout << " ");
		}
		cout << endl;
	}
}

void anamenu() {
	int secimmenu;

	ifstream kayitSayacOku("Save.txt", ios::in);
	kayitSayacOku.close();
	system("cls");

	hosgeldiniz();
	hizala(2, 6); cout << "    Ana Men�"; hizala(1, 6); cout << "-------------------"; hizala(2, 6); cout << "1) Yeni Oyuna Ba�la"; hizala(1, 6); cout << "2) Kay�tl� Oyunlar"; hizala(1, 6); cout << "3) Yap�mc�"; hizala(1, 6); cout << "4) Yard�m"; hizala(1, 6); cout << "5) Oyundan ��k";
	hizala(2, 6); cout << "Ne yapmak istiyorsunuz ? : "; cin >> secimmenu;
	switch (secimmenu) {
	case 1:
		zorluk();
		break;
	case 2:
		if (!kayitSayacOku || kayitSayacOku.tellg() == 0) {
			hizala(1, 6);	cout << "!! Kay�tl� oyun bulunamad�. !!";
		}
		else
			savemenu();
		break;
	case 3:
		hizala(1, 5);
		harfOku(message.producer, message.producer.length());
		break;
	case 4:
		hizala(1, 5); cout << "Oyun zindan temizleyip g��lenme �zerine kurulu bir oyundur."; hizala(1, 5); cout << "Oyundan ��karsan�z mevcut ilerlemeniz kaydedilmeyecektir!"; hizala(1, 5); cout << "10 Levele ula�t���n�zda bir adet pet se�meniz gerekecek.";
		Sleep(1000);
		break;
	case 5:
		hizala(1, 6); harfOku(message.seeYou, message.seeYou.length());
		Sleep(500);
		exit(0);
		break;
	default:
		hizala(1, 6);
		cout << "!! Yanl�� giri� yapt�n�z. !!";
		break;
	}
	Sleep(2000);
	anamenu();
}
void zorluk() {
	int zorluksecim;
	system("cls");
	hosgeldiniz();
	hizala(2, 6); cout << " Zorluk Men�s�"; hizala(1, 6); cout << "---------------"; hizala(2, 6); cout << "1) Kolay"; hizala(1, 6); cout << "2) Orta"; hizala(1, 6); cout << "3) Zor\n";
	hizala(1, 6); cout << "Oyun zorlu�unu se�in : ";	cin >> zorluksecim;
	switch (zorluksecim) {
	case 1:
		character.setHealt(2000);
		character.setAttack(350);
		character.setGold(300);
		firstAid.setEffect(500);
		firstAid.setCount(5);
		grenade.setEffect(500);
		grenade.setCount(5);
		break;
	case 2:
		character.setHealt(1500);
		character.setAttack(250);
		character.setGold(200);
		firstAid.setEffect(300);
		firstAid.setCount(3);
		grenade.setEffect(300);
		grenade.setCount(3);
		break;
	case 3:
		character.setHealt(1000);
		character.setAttack(150);
		character.setGold(100);
		firstAid.setEffect(200);
		firstAid.setCount(1);
		grenade.setEffect(200);
		grenade.setCount(1);
		break;
	default:
		hizala(1, 6);
		cout << "!! Yanl�� giri� yapt�n�z. !!";
		Sleep(1500);
		zorluk();
		break;
	}
	karaktersecme();
}
void karaktersecme() {
	int karaktersecim;
	system("cls");
	hosgeldiniz();
	hizala(1, 6); cout << "Karakter Se�im Men�s�"; hizala(1, 6); cout << "---------------------";
	hizala(2, 2); cout << "    1) Geralth \t\t    2) Cirilla \t\t    3) Yennefer \t    4) Vesemir"; hizala(1, 2); cout << "-------------------\t-------------------\t-------------------\t-------------------";
	hizala(1, 2); cout << "> Can  : " << character.getHealt() + 250 << "\t\t> Can  : " << character.getHealt() + 450 << "\t\t> Can  : " << character.getHealt() + 100 << "\t\t> Can  : " << character.getHealt() + 450;
	hizala(1, 2); cout << "> Atak : " << character.getAttack() + 50 << "\t\t> Atak : " << character.getAttack() + 20 << "\t\t> Atak : " << character.getAttack() + 100 << "\t\t> Atak : " << character.getAttack() + 20;
	hizala(1, 2); cout << "> �lk Yard�m : +" << firstAid.getEffect() + 150 << "\t> �lk Yard�m : +" << firstAid.getEffect() + 300 << "\t> �lk Yard�m : +" << firstAid.getEffect() + 50 << "\t> �lk Yard�m : +" << firstAid.getEffect() + 150;
	hizala(1, 2); cout << "> Bomba Hasar : " << grenade.getEffect() + 175 << "\t> Bomba Hasar : " << grenade.getEffect() + 100 << "\t> Bomba Hasar : " << grenade.getEffect() + 300 << "\t> Bomba Hasar : " << grenade.getEffect() + 175;

	hizala(2, 6); cout << "Se�mek istedi�iniz karakter ? : ";	cin >> karaktersecim;
	switch (karaktersecim) {
	case 1:
		character.setHealt(character.getHealt() + 250);
		character.setAttack(character.getAttack() + 50);
		firstAid.setEffect(firstAid.getEffect() + 150);
		grenade.setEffect(grenade.getEffect() + 175);
		break;
	case 2:
		character.setHealt(character.getHealt() + 450);
		character.setAttack(character.getAttack() + 20);
		firstAid.setEffect(firstAid.getEffect() + 300);
		grenade.setEffect(grenade.getEffect() + 100);
		break;
	case 3:
		character.setHealt(character.getHealt() + 100);
		character.setAttack(character.getAttack() + 100);
		firstAid.setEffect(firstAid.getEffect() + 50);
		grenade.setEffect(grenade.getEffect() + 300);
		break;
	case 4:
		character.setHealt(character.getHealt() + 450);
		character.setAttack(character.getAttack() + 20);
		firstAid.setEffect(firstAid.getEffect() + 150);
		grenade.setEffect(grenade.getEffect() + 175);
		break;
	default:
		hizala(1, 6);
		cout << "!! Yanl�� giri� yapt�n�z. !!";
		Sleep(1500);
		karaktersecme();
		break;
	}

	character.setMaxHealt(character.getHealt());
	oyunmenu();
}
int petsecme() {
	int petsecim;
	system("cls");
	hosgeldiniz();
	hizala(1, 6); cout << "Pet Se�im Men�s�"; hizala(1, 6); cout << "----------------";
	hizala(2, 2); cout << "  1) Yavru Aslan \t  2) Yavru Maymun \t  3) Yavru �r�mcek \t  4) Yavru Akrep"; hizala(1, 2); cout << "-------------------\t-------------------\t-------------------\t-------------------";
	hizala(1, 2); cout << "> Can  : " << character.getMaxHealt() + 250 << "\t\t> Can  : " << character.getMaxHealt() + 450 << "\t\t> Can  : " << character.getMaxHealt() + 100 << "\t\t> Can  : " << character.getMaxHealt() + 250;
	hizala(1, 2); cout << "> Atak : " << character.getAttack() + 100 << "\t\t> Atak : " << character.getAttack() + 20 << "\t\t> Atak : " << character.getAttack() + 50 << "\t\t> Atak : " << character.getAttack() + 100;
	hizala(1, 2); cout << "> Tecr�be : +" << character.getExtraExperience() + 100 << "\t> Tecr�be : +" << character.getExtraExperience() + 200 << "\t> Tecr�be : +" << character.getExtraExperience() + 300 << "\t> Tecr�be : +" << character.getExtraExperience() + 300;
	if (character.getCriticalChance() < 75) {
		hizala(1, 2); cout << "> Kritik �ans� : " << character.getCriticalChance() + 15 << "\t> Kritik �ans� : " << character.getCriticalChance() + 15 << "\t> Kritik �ans� : " << character.getCriticalChance() + 25 << "\t> Kritik �ans� : " << character.getCriticalChance() + 25;
	}
	hizala(2, 6); cout << "Hangi peti almak istiyorsunuz ? : ";	cin >> petsecim;
	switch (petsecim) {
	case 1:
		character.setMaxHealt(character.getMaxHealt() + 250);
		character.setAttack(character.getAttack() + 100);
		character.setExtraExperience(character.getExtraExperience() + 10);
		if (character.getCriticalChance() <= 90)
			character.setCriticalChance(character.getCriticalChance() + 10);
		else
			character.setCriticalChance(100);
		return 1;
		break;
	case 2:
		character.setMaxHealt(character.getMaxHealt() + 450);
		character.setAttack(character.getAttack() + 20);
		character.setExtraExperience(character.getExtraExperience() + 20);
		if (character.getCriticalChance() <= 90)
			character.setCriticalChance(character.getCriticalChance() + 10);
		else
			character.setCriticalChance(100);
		return 2;
		break;
	case 3:
		character.setMaxHealt(character.getMaxHealt() + 100);
		character.setAttack(character.getAttack() + 50);
		character.setExtraExperience(character.getExtraExperience() + 30);
		if (character.getCriticalChance() <= 80)
			character.setCriticalChance(character.getCriticalChance() + 20);
		else
			character.setCriticalChance(100);
		return 3;
		break;
	case 4:
		character.setMaxHealt(character.getMaxHealt() + 250);
		character.setAttack(character.getAttack() + 100);
		character.setExtraExperience(character.getExtraExperience() + 30);
		if (character.getCriticalChance() <= 80)
			character.setCriticalChance(character.getCriticalChance() + 20);
		else
			character.setCriticalChance(100);
		return 4;
		break;
	default:
		hizala(1, 6);
		cout << "!! Yanl�� giri� yapt�n�z. !!";
		Sleep(1500);
		petsecme();
		break;
	}
	return 0;
	oyunmenu();
}
void karakterstatu() {
	int statumenu;
	game.setReadHiScore(hiscoreOku()); //Dosyada kay�t varsa en y�ksek skoru al, kay�t yoksa �u anki skoru al
	system("cls");
	hosgeldiniz();
	system("COLOR 3");
	hizala(2, 6); cout << "Karakter Stat�leri"; hizala(1, 6); cout << "------------------";
	hizala(1, 5); cout << "Toplam Skor : " << game.getTotalScore(); if (game.getTotalScore() > game.getHiScore()) { game.setHiScore(game.getTotalScore()); } cout << "\t Y�ksek Skor : "; (game.getHiScore() > game.getReadHiScore()) ? (cout << game.getHiScore()) : (cout << game.getReadHiScore());
	hizala(2, 6); cout << "> Level : " << character.getLevel(); hizala(1, 6); cout << "> Tecr�be : " << character.getExperience() << " / " << (character.getLevel() * 50); hizala(1, 6); cout << "> Can   : " << character.getHealt() << " / " << character.getMaxHealt(); hizala(1, 6); cout << "> Atak  : " << character.getAttack(); hizala(1, 6); cout << "> Alt�n : " << character.getGold(); hizala(1, 6); cout << "> Kritik �ans� : % " << character.getCriticalChance(); hizala(1, 6); cout << "> Dodge �ans� : % " << character.getDodgeChance();	if (character.getLevel() >= 10) { hizala(1, 6); cout << "> Pet Level : " << pet.getLevel(); hizala(1, 6); cout << "> Pet Tecr�be : " << pet.getExperience() << " / " << pet.getLevel() * 50; }
	hizala(2, 6); cout << "1) Stat� Geli�tir (" << character.getStatusScore() << ")"; hizala(1, 6); cout << "2) Men�ye geri d�n"; hizala(1, 6); cout << "3) Oyundan ��k\n";
	hizala(1, 6); cout << "Ne Yapmak �stiyorsunuz ? : "; cin >> statumenu;
	switch (statumenu) {
	case 1:
		if (character.getStatusScore() > 0)
			statugelistir();
		else {
			hizala(1, 6);
			cout << "Yeterli stat� puan�n�z yok";
			Sleep(1000);
			karakterstatu();
		}
		break;
	case 2:
		oyunmenu();
		break;
	case 3:
		hizala(1, 6);
		cout << "Tekrar g�r��mek �zere ";
		Sleep(500);
		exit(0);
		break;
	default:
		hizala(1, 6);
		cout << "!! Yanl�� giri� yapt�n�z. !!";
		Sleep(1000);
		karakterstatu();
		break;
	}
}
void statugelistir() {
	int statusecim;
	hizala(2, 6); cout << "1) Can (+100)"; hizala(1, 6); cout << "2) Atak (+50)"; hizala(1, 6); cout << "3) Kritik �ans (+ %5)"; hizala(1, 6); cout << "4) Dodge (+ %1)";
	hizala(2, 6); cout << "Ne yapmak istiyorsunuz : ";	cin >> statusecim;
	switch (statusecim) {
	case 1:
		character.setMaxHealt(character.getMaxHealt() + 100);
		break;
	case 2:
		character.setAttack(character.getAttack() + 50);
		break;
	case 3:
		if (character.getCriticalChance() <= 95)
			character.setCriticalChance(character.getCriticalChance() + 5);
		else {
			hizala(1, 5);
			cout << "% 100 Kritik isabet �ans�na ula�m��s�n�z.";
			Sleep(1000);
			karakterstatu();
		}
		break;
	case 4:
		if (character.getDodgeChance() <= 29)
			character.setDodgeChance(character.getDodgeChance() + 1);
		else {
			hizala(1, 5);
			cout << "% 30 Dodge �ans�na ula�m��s�n�z.";
			Sleep(1000);
			karakterstatu();
		}
		break;
	default:
		hizala(1, 6);
		cout << "!! Yanl�� giri� yapt�n�z. !!";
		Sleep(1000);
		karakterstatu();
		break;
	}
	character.setStatusScore(character.getStatusScore() - 1);
	karakterstatu();
}
void kayitListele() {
	int sayac = 0, karsilastirSayac = 0, okunanMax = 0, kayitsecim, kayitseccevap, Okunan[20], * OkunanKarsilastir = new int[100];
	ifstream KayitOku("Save.txt", ios::in);
	if (!KayitOku || KayitOku.tellg() == 0) {//Dosya yoksa veya bo�sa al�nacak kay�t
		KayitOku.close();
		save(1);
		oyunmenu();
	}
	else { //Dosya varsa
		while (!KayitOku.eof())
		{
			for (int i = 0; i < 20; i++) {//Kay�t Oku
				KayitOku >> Okunan[i];
				if (i == 0) { //Kay�t numaralar�n� al
					OkunanKarsilastir[karsilastirSayac] = Okunan[0];
					karsilastirSayac++;
				}
			}
			hizala(1, 6); cout << "Kay�t " << Okunan[0] << ")" << " Karakter Level : " << Okunan[1];
			sayac++;
			if (sayac == 1) //ilk d�ng�de okunanmax de�erine ilk okunan de�er atand�
				okunanMax = Okunan[0];
			if (Okunan[0] > okunanMax) //okunan de�erlerden max olan� ara�t�r�ld�
				okunanMax = Okunan[0];
		}
		KayitOku.close();
		hizala(2, 6); cout << "1) Yeni Kay�t"; hizala(1, 6); cout << "2) Kay�t �zerine Yaz"; hizala(1, 6); cout << "3) Men�ye Geri D�n";
		hizala(2, 6); cout << "Ne yapmak istiyorsunuz ? : "; cin >> kayitseccevap;
		if (kayitseccevap == 1) { //Yeni Kay�t
			okunanMax++;
			KayitOku.close();
			save(okunanMax);
		}
		else if (kayitseccevap == 2) { //Kay�t �zerine
			int dogrugiris = 0;
			hizala(1, 6); cout << "Hangi kayd�n �zerine kaydedilsin ? : ";	cin >> kayitsecim;
			for (int i = 0; i < karsilastirSayac; i++) {
				if (kayitsecim == OkunanKarsilastir[i]) { //Dosyadaki kay�tlardan birini se�erse
					dogrugiris = 1;
					KayitOku.close();
					save(kayitsecim);
				}
			}
			if (dogrugiris == 0) { //Dosyadaki kay�tlardan herhangi birini se�mezse
				system("cls");
				hosgeldiniz();
				kayitListele();
			}
		}
		else if (kayitseccevap == 3)
			oyunmenu();
		else {
			hizala(1, 6);
			cout << "!! Yanl�� giri� yapt�n�z. !!";
			Sleep(1000);
			oyunmenu();
		}
	}
}
void KayitSil(int silinecekKayit) {
	Temp temp{};

	int gecici = 0;
	ifstream KayitOku("Save.txt", ios::in);
	ofstream KayitYaz("Save1.txt", ios::app);

	while (!KayitOku.eof())
	{
		KayitOku >> temp.saveNo >> temp.level >> temp.experience >> temp.healt >> temp.maxHealt >> temp.attack >> temp.gold >> temp.statusScore >> temp.petLevel >> temp.petExperience >> temp.firstAidEffect >> temp.firstAidCount >> temp.grenadeEffect >> temp.grenadeCount >> temp.criticalChance >> temp.dodgeChance >> temp.extraExperience >> temp.debt >> temp.totalScore >> temp.hiScore;
		if (silinecekKayit == temp.saveNo) {//Gelen numara dosyadan okunan numarayla e�le�irse kayd� dosyaya yazma
			hizala(1, 6); cout << "Silme i�lemi ba�ar�yla ger�ekle�tirildi.";
			Sleep(1000);
			gecici = 1;
		}
		else { //e�le�en numara yoksa okunan kayd� dosyaya yaz
			KayitYaz << "\n" << temp.saveNo << " " << temp.level << " " << temp.experience << " " << temp.healt << " " << temp.maxHealt << " " << temp.attack << " " << temp.gold << " " << temp.statusScore << " " << temp.petLevel << " " << temp.petExperience << " " << temp.firstAidEffect << " " << temp.firstAidCount << " " << temp.grenadeEffect << " " << temp.grenadeCount << " " << temp.criticalChance << " " << temp.dodgeChance << " " << temp.extraExperience << " " << temp.debt << " " << temp.totalScore << " " << temp.hiScore;
			gecici = 2;
		}
	}
	if (gecici == 0) //Dosya bo�sa
		cout << "Dosyada Kay�t yok";
	KayitOku.close();
	KayitYaz.close();
	remove("Save.txt");
	rename("Save1.txt", "Save.txt");

	ifstream Kayitsiz("Save.txt", ios::in);
	Kayitsiz.close();
	if (helper.is_empty(Kayitsiz)) //Dosyada kay�t yoksa sil ()
		remove("Save.txt");

	oyunmenu();
}

void oyunmenu() {
	int oyunmenusecim, Okunan[20] = {}, silKayit;
	ifstream KayitOku("Save.txt", ios::in); //Switch case in her se�imi i�in dosya a��k kalmas�n diye kapatmak gerekiyor. !!
	system("cls");
	hosgeldiniz();
	hizala(2, 6); cout << "   Oyun Men�s�"; hizala(1, 6); cout << "-----------------"; hizala(2, 6); cout << "1) Karakter Stat� (" << character.getStatusScore() << ")"; hizala(1, 6); cout << "2) Envanter"; hizala(1, 6); cout << "3) Ma�aza"; hizala(1, 6); cout << "4) Banka"; hizala(1, 6); cout << "5) Zindanlar"; hizala(1, 6); cout << "6) Oyunu Kaydet"; hizala(1, 6); cout << "7) Kay�tl� Oyunu Sil"; hizala(1, 6); cout << "8) Oyundan ��k\n";
	hizala(1, 6); cout << "Ne yapmak istiyorsunuz ? : "; cin >> oyunmenusecim;
	switch (oyunmenusecim) {
	case 1:
		KayitOku.close();
		karakterstatu();
		break;
	case 2:
		KayitOku.close();
		envanter();
		break;
	case 3:
		KayitOku.close();
		magaza();
		break;
	case 4:
		KayitOku.close();
		banka();
		break;
	case 5:
		KayitOku.close();
		if (character.getHealt() > 0)
			zindanlar();
		else {
			hizala(1, 5); cout << "    �lk yard�m �antas� kullanman�z gerekiyor.";
			Sleep(1500);
			oyunmenu();
		}
		break;
	case 6:
		KayitOku.close();
		kayitListele();
		break;
	case 7:
		if (helper.is_empty(KayitOku)) {//Dosya bo�sa
			hizala(1, 6); cout << "Kay�t Bulunamad�";	Sleep(1000);
			KayitOku.close();
			remove("Save.txt");
			oyunmenu();
		}
		while (!KayitOku.eof())
		{
			for (int i = 0; i < 20; i++) //Kay�t oku
				KayitOku >> Okunan[i];
			hizala(1, 6); cout << "Kay�t " << Okunan[0] << ") Karakter Level : " << Okunan[1];
		}
		hizala(1, 6); cout << Okunan[0] + 1 << ") Vazge�";
		KayitOku.close();
		hizala(2, 6); cout << "Hangi kayd� silmek istiyorsunuz ? : ";	cin >> silKayit;
		if (silKayit == Okunan[0] + 1)
			oyunmenu();
		KayitSil(silKayit);
		break;
	case 8:
		KayitOku.close();
		hizala(1, 6); harfOku(message.seeYou, message.seeYou.length());
		Sleep(500);
		exit(0);
		break;
	case 9:
		KayitOku.close();
		hiscoreOku();
		break;
	default:
		KayitOku.close();
		hizala(1, 6); cout << "!! Yanl�� giri� yapt�n�z. !!";
		Sleep(1000);
		oyunmenu();
		break;
	}
}
int esyakullan(int rakipcani) {
	int esyakullan;
	if (firstAid.getCount() > 0 || grenade.getCount() > 0) {
		hizala(1, 6); cout << "1) �lk yard�m �antas� (+" << firstAid.getEffect() << " Can)"; hizala(1, 6); cout << "2) El bombas� (" << grenade.getEffect() << " Hasar)"; hizala(1, 6); cout << "3) Vazge�\n"; hizala(1, 6); cout << "Ne yapmak istiyorsunuz ? : "; cin >> esyakullan;
		switch (esyakullan) {
		case 1:
			if (firstAid.getCount() > 0 && (character.getHealt() != character.getMaxHealt())) {
				character.setHealt(character.getHealt() + firstAid.getEffect());
				if (character.getHealt() > character.getMaxHealt())
					character.setHealt(character.getMaxHealt());
				firstAid.setCount(firstAid.getCount() - 1);
			}
			else if (firstAid.getCount() > 0 && (character.getHealt() == character.getMaxHealt())) {
				hizala(1, 5); cout << "�lk yard�m �antas�na ihtiyac�n yok gibi g�r�n�yor.";
				Sleep(1000);
			}
			else {
				hizala(1, 3); cout << "Malesef elinizde ilk yard�m �antas� bulunmuyor. Ma�azaya giderek sat�n alabilirsiniz.";
				Sleep(1000);
			}
			break;
		case 2:
			if (grenade.getCount() > 0) {
				rakipcani -= grenade.getEffect();
				grenade.setCount(grenade.getCount() - 1);
				if (rakipcani < 0) {
					cout << "Tebrikler zindan� ba�ar�yla tamamlayarak 200 alt�n kazand�n�z.";
					character.setGold(character.getGold() + 200);
				}
			}
			else {
				hizala(1, 4); cout << "Malesef elinizde el bombas� bulunmuyor. Ma�azaya giderek sat�n alabilirsiniz.";
				Sleep(1000);
			}
			break;
		case 3:
			return rakipcani;
			break;
		default:
			hizala(1, 6); cout << "!! Yanl�� giri� yapt�n�z. !!";
			Sleep(1000);
			break;
		}
	}
	else {
		hizala(1, 4); cout << "Malesef envanterinizde kullan�lacak hi�bir ��e bulunmuyor.";
		Sleep(1500);
	}
	return rakipcani;
}
void envanter() {
	int envantersecim;
	system("cls");
	hosgeldiniz();
	hizala(1, 6); cout << "    Envanter"; hizala(1, 6); cout << "    --------\n";
	if (firstAid.getCount() > 0) {
		hizala(1, 6); cout << "> �lk Yard�m : " << firstAid.getCount();
	}
	if (grenade.getCount() > 0) {
		hizala(1, 6); cout << "> El Bombas� : " << grenade.getCount();
	}
	hizala(2, 6); cout << "1) Men�ye Geri D�n"; hizala(2, 6); cout << "Ne Yapmak �stiyorsunuz : "; cin >> envantersecim;
	switch (envantersecim) {
	case 1:
		oyunmenu();
		break;
	default:
		hizala(1, 6);
		cout << "!! Yanl�� giri� yapt�n�z. !!";
		Sleep(1000);
		envanter();
		break;
	}
}
void magaza() {
	int magazasecim;
	system("cls");
	hosgeldiniz();
	hizala(1, 6); cout << "      Ma�aza"; hizala(1, 6); cout << "------------------"; hizala(1, 6); cout << "Paran�z : " << character.getGold(); hizala(2, 6); cout << "1) �lk yard�m �antas� \t> 100 Alt�n"; hizala(1, 6); cout << "2) El bombas� \t\t> 150 Alt�n"; hizala(1, 6); cout << "3) Men�ye geri d�n";
	hizala(2, 6); cout << "Ne sat�n almak istiyorsunuz ? : ";	cin >> magazasecim;
	switch (magazasecim) {
	case 1:
		if (character.getGold() >= firstAid.getCost()) {
			firstAid.setCount(firstAid.getCount() + 1);
			character.setGold(character.getGold() - firstAid.getCost());
		}
		else {
			hizala(1, 6); cout << "�zg�n�z.. Yeterli alt�n�n�z yok.";
			Sleep(2000);
		}
		magaza();
		break;
	case 2:
		if (character.getGold() >= grenade.getCost()) {
			grenade.setCount(grenade.getCount() + 1);
			character.setGold(character.getGold() - grenade.getCost());
		}
		else {
			hizala(1, 6); cout << "�zg�n�z.. Yeterli alt�n�n�z yok.";
			Sleep(2000);
		}
		magaza();
		break;
	case 3:
		oyunmenu();
		break;
	default:
		hizala(1, 6); cout << "!! Yanl�� giri� yapt�n�z. !!";
		Sleep(1500);
		magaza();
		break;
	}
}
void banka() {
bankabas:
	int bankasecim, alimsecim, borcode = 0, sayac = 1;
	char borcodeonay;
	system("cls");
	hosgeldiniz();
	hizala(1, 6); cout << "       Banka"; hizala(1, 6); cout << "    -----------"; hizala(1, 6); cout << "Alt�n�n�z : " << character.getGold() << "   Borcunuz : " << character.getDebt(); hizala(2, 6);
	cout << sayac << ") Alt�n al"; sayac++;
	if (character.getDebt() > 0) {
		hizala(1, 6); cout << sayac << ") Bor� �de"; sayac++;
	}
	hizala(1, 6); cout << sayac << ") Bankadan ��k";
	hizala(2, 6); cout << "Ne yapmak istiyorsunuz ? : "; cin >> bankasecim;
	if (bankasecim == 1) {
		hizala(1, 6); cout << "1) +250 Alt�n (%20 Faiz)"; hizala(1, 6); cout << "2) +500 Alt�n (%20 Faiz)"; hizala(1, 6); cout << "3) +1000 Alt�n (%20 Faiz)"; hizala(1, 6); cout << "4) Vazge�\n";
		hizala(1, 6); cout << "Ne yapmak istiyorsunuz ? : "; cin >> alimsecim;
		hizala(1, 6);
		switch (alimsecim) {
		case 1:
			character.setGold(character.getGold() + 250);
			character.setDebt(character.getDebt() + 250 * 1.2);
			cout << "Hesab�n�za 250 Alt�n ba�ar�yla yat�r�lm��t�r.";
			break;
		case 2:
			character.setGold(character.getGold() + 500);
			character.setDebt(character.getDebt() + 500 * 1.2);
			cout << "Hesab�n�za 500 Alt�n ba�ar�yla yat�r�lm��t�r.";
			break;
		case 3:
			character.setGold(character.getGold() + 1000);
			character.setDebt(character.getDebt() + 1000 * 1.2);
			cout << "Hesab�n�za 1000 Alt�n ba�ar�yla yat�r�lm��t�r.";
			break;
		case 4:
			banka();
			break;
		default:
			cout << "!! Yanl�� giri� yapt�n�z. !! \n";
			Sleep(1500);
			banka();
			break;
		}
	}
	else if (character.getDebt() > 0 && bankasecim == 2) {
		hizala(2, 6); cout << "Ne kadar �demek istiyorsunuz : ";	cin >> borcode;
		if (borcode <= character.getDebt()) {
			hizala(1, 3); cout << character.getDebt() << " Alt�n olan borcunuzun " << borcode << " Alt�n kadar�n� �deyeceksiniz. Onayl�yor musunuz ? (E / H) : ";	cin >> borcodeonay;
			switch (borcodeonay) {
			case 'E':
			case 'e':
				if (character.getGold() >= borcode) {
					character.setDebt(character.getDebt() - borcode);
					character.setGold(character.getGold() - borcode);
				}
				else {
					cout << "�zg�n�z. Hesab�n�zda yeterli alt�n bulunmamaktad�r.";
					Sleep(1500);
				}
				break;
			case 'H':
			case 'h':
				break;
			default:
				cout << "!! Yanl�� giri� yapt�n�z. !!";
				Sleep(1500);
				break;
			}
			banka();
		}
	}
	else if (bankasecim == sayac) //Sayac�n max de�eri girilirse men�ye d�n
		oyunmenu();
	else {
		hizala(1, 6); cout << "!! Yanl�� giri� yapt�n�z. !!";
	}
	Sleep(1500);
	goto bankabas;
}
void zindanlar() {
	int zindansecim;
	system("cls");
	hosgeldiniz();
	hizala(2, 6); cout << "    Zindanlar"; hizala(1, 6); cout << "-----------------"; hizala(2, 6); cout << "1) �r�mcek Zindan� (Minimum Lv 1)"; hizala(1, 6); cout << "2) Maymun Zindan�  (Minimum Lv 5)"; hizala(1, 6); cout << "3) Men�ye geri d�n";
	hizala(2, 6); cout << "Ne yapmak istiyorsunuz ? : "; cin >> zindansecim;
	switch (zindansecim) {
	case 1:
		orumcekzindani();
		break;
	case 2:
		if (character.getLevel() > 5)
			maymunzindani();
		else {
			hizala(1, 6); cout << "�zg�n�z.. Malesef yeterli seviyeye ula�mam��s�n�z.";
			Sleep(1500);
			zindanlar();
		}
		break;
	case 3:
		oyunmenu();
		break;
	default:
		hizala(1, 6); cout << "!! Yanl�� giri� yapt�n�z. !!";
		Sleep(1000);
		zindanlar();
		break;
	}
}
void orumcekzindani() { //cikissayac zindanda eylem yaparsan ve zindan� bitirmeden ��karsan ceza
	int zindankarar, cikissayac = 0, raund = 1;
	Mob spider(700, 700, 200, 50);
zindanbas:
	system("cls");
	hosgeldiniz();
	hizala(1, 6); cout << "> �R�MCEK Z�NDANI <\n\tOyuncunun Stat�leri"; hizala(0, 8); cout << "�r�mce�in Stat�leri\n\t-------------------"; hizala(0, 8); cout << "-------------------\n\t> Can  : " << character.getHealt() << " / " << character.getMaxHealt(); hizala(0, 8); cout << "> Can  : " << spider.getHealt() << " / " << spider.getMaxHealt() << "\n\t> Atak : " << character.getAttack(); hizala(0, 9); cout << "> Atak : " << spider.getAttack() << "\n\t> Sahip Olunanlar \n\t    �lk yard�m �antas� : " << firstAid.getCount() << "\n\t    El bombas� : " << grenade.getCount();
	if (spider.getHealt() > 0 && character.getHealt() > 0) {
		hizala(1, 7); cout << "Raund < " << raund << " >";
		hizala(2, 5); cout << "1) Atak      2) E�ya kullan \t 3) Zindandan ��k";	hizala(2, 6); cout << "Ne yapmak istiyorsunuz ? : "; cin >> zindankarar;
		switch (zindankarar) {
		case 1:
			cikissayac++;
			raund++;
			kritik = rand() % 101;
			dodge = rand() % 101;
			spider.setHealt(spider.getHealt() - character.getAttack() + rand() % 10);
			character.setHealt(character.getHealt() - spider.getAttack() + rand() % 10);

			// Kritik
			if (character.getCriticalChance() != 0 && kritik > 0 && kritik <= character.getCriticalChance()) {
				spider.setHealt(spider.getHealt() - character.getAttack());
				hizala(1, 7);
				harfOku(message.critical, message.critical.length());
				Sleep(500);
			}
			// Dodge
			if (spider.getHealt() > 0) {
				if (character.getDodgeChance() != 0 && dodge > 0 && dodge <= character.getDodgeChance()) {
					character.setHealt(character.getHealt() + spider.getAttack()); hizala(1, 7);
					harfOku(message.dodge, message.dodge.length());
					Sleep(500);
				}
			}

			if (spider.getHealt() <= 0) {
				character.setGold(character.getGold() + 200);
				character.setExperience(character.getExperience() + spider.getExperience() + character.getExtraExperience());
				game.setTotalScore(game.getTotalScore() + 5);
				if (game.getTotalScore() > game.getHiScore())
					game.setHiScore(game.getTotalScore());
				if (pet.getPetReturn() != 0)
					pet.setExperience(pet.getExperience() + 10);
				hizala(1, 4); cout << "Tebrikler zindan� ba�ar�yla tamamlayarak 200 alt�n, " << spider.getExperience() + character.getExtraExperience() << " tecr�be puan� kazand�n�z.";
				Sleep(1500);
				level();	petlvl();
				oyunmenu();
			}
			if (character.getHealt() <= 0) {
				hizala(1, 7); harfOku(message.death, message.death.length()); Sleep(1000);
				oyunmenu();
			}
			goto zindanbas;
			break;
		case 2:
			cikissayac++;
			spider.setHealt(esyakullan(spider.getHealt()));
			goto zindanbas;
			break;
		case 3:
			if (cikissayac != 0) {
				hizala(1, 6); cout << "100 alt�n kaybettiniz.";
				character.setGold(character.getGold() - 100);
				Sleep(1000);
			}
			oyunmenu();
			break;
		default:
			hizala(1, 6); cout << "!! Yanl�� giri� yapt�n�z. !!";
			Sleep(1000);
			orumcekzindani();
			break;
		}

	}
	else if (spider.getHealt() <= 0) {
		character.setGold(character.getGold() + 200);
		character.setExperience(character.getExperience() + spider.getExperience() + character.getExtraExperience());
		game.setTotalScore(game.getTotalScore() + 5);
		if (game.getTotalScore() > game.getHiScore())
			game.setHiScore(game.getTotalScore());
		if (pet.getPetReturn() != 0)
			pet.setExperience(pet.getExperience() + 10);
		hizala(1, 4); cout << "Tebrikler zindan� ba�ar�yla tamamlayarak 200 alt�n, " << spider.getExperience() + character.getExtraExperience() << " tecr�be puan� kazand�n�z.";
		Sleep(1500);
		level();	petlvl();
		oyunmenu();
	}
	else if (character.getHealt() <= 0) {
		hizala(1, 6); harfOku(message.death, message.death.length());
		Sleep(1500);
		oyunmenu();
	}
}
void maymunzindani() {
	hizala(1, 6); harfOku(message.inTheMaking, message.inTheMaking.length());
	oyunmenu();
}
void level() {
	while (character.getExperience() >= (character.getLevel() * 50)) {
		system("cls");
		hizala(13, 6); cout << character.getLevel() << " "; harfOku(message.levelUp, message.levelUp.length());
		character.setExperience(character.getExperience() - (character.getLevel() * 50));
		character.setLevel(character.getLevel() + 1);
		character.setHealt(character.getMaxHealt());
		character.setStatusScore(character.getStatusScore() + 1);
	}
	if (character.getLevel() == 10)
		pet.setPetReturn(petsecme());
}
void petlvl() {
	while (pet.getExperience() >= (pet.getLevel() * 50)) {
		pet.setExperience(pet.getExperience() - (pet.getLevel() * 50));
		pet.setLevel(pet.getLevel() + 1);
		switch (pet.getPetReturn()) {
		case 1:
			character.setMaxHealt(character.getMaxHealt() + 10);
			character.setAttack(character.getAttack() + 15);
			character.setExtraExperience(character.getExtraExperience() + 5);
			if (character.getCriticalChance() <= 98)
				character.setCriticalChance(character.getCriticalChance() + 2);
			else
				character.setCriticalChance(100);
			break;
		case 2:
			character.setMaxHealt(character.getMaxHealt() + 15);
			character.setAttack(character.getAttack() + 5);
			character.setExtraExperience(character.getExtraExperience() + 10);
			if (character.getCriticalChance() <= 98)
				character.setCriticalChance(character.getCriticalChance() + 2);
			else
				character.setCriticalChance(100);
			break;
		case 3:
			character.setMaxHealt(character.getMaxHealt() + 5);
			character.setAttack(character.getAttack() + 10);
			character.setExtraExperience(character.getExtraExperience() + 15);
			if (character.getCriticalChance() <= 97)
				character.setCriticalChance(character.getCriticalChance() + 3);
			else
				character.setCriticalChance(100);
			break;
		case 4:
			character.setMaxHealt(character.getMaxHealt() + 10);
			character.setAttack(character.getAttack() + 15);
			character.setExtraExperience(character.getExtraExperience() + 15);
			if (character.getCriticalChance() <= 97)
				character.setCriticalChance(character.getCriticalChance() + 3);
			else
				character.setCriticalChance(100);
			break;
		}
	}
}
void savemenu() {
	int sayac = 0, kayitsecim;
	Temp temp{};

	system("cls");
	hosgeldiniz();
	hizala(1, 6); cout << "    Kay�t Men�s�"; hizala(1, 6); cout << "  ----------------\n";
	ifstream KayitOkuma("Save.txt", ios::in);
	while (!KayitOkuma.eof())
	{
		KayitOkuma >> temp.saveNo >> temp.level >> temp.experience >> temp.healt >> temp.maxHealt >> temp.attack >> temp.gold >> temp.statusScore >> temp.petLevel >> temp.petExperience >> temp.firstAidEffect >> temp.firstAidCount >> temp.grenadeEffect >> temp.grenadeCount >> temp.criticalChance >> temp.dodgeChance >> temp.extraExperience >> temp.debt >> temp.totalScore >> temp.hiScore;
		hizala(1, 6); cout << "Kay�t " << sayac + 1 << ")" << " Karakter Level : " << temp.level;
		sayac++;
	}
	KayitOkuma.close();
	hizala(2, 6); cout << sayac + 1 << ") Ana Men�ye Geri D�n" << endl;
	do
	{
		hizala(1, 6); cout << "Hangi kayd� oynamak istiyorsunuz ? : ";	cin >> kayitsecim;
		if (kayitsecim == sayac + 1)
			anamenu();
	} while (kayitsecim <= 0 || kayitsecim > sayac);
	dosyakayitOku(kayitsecim);
}
void save(int gelenKayitNo) {
	int Okunan[20]{}, gecici = 0; // ilk while d�ng�s�nde gecici de�eri de�i�mezse yeni kay�t eklendi�ini anla
	game.setReadHiScore(hiscoreOku());
	if (gelenKayitNo == 1) {//�nceden kay�t yoksa
		ofstream ilkKayit("Save.txt", ios::out);
		ilkKayit << "\n" << gelenKayitNo << " " << character.getLevel() << " " << character.getExperience() << " " << character.getHealt() << " " << character.getMaxHealt() << " " << character.getAttack() << " " << character.getGold() << " " << character.getStatusScore() << " " << pet.getLevel() << " " << pet.getExperience() << " " << firstAid.getEffect() << " " << firstAid.getCount() << " " << grenade.getEffect() << " " << grenade.getCount() << " " << character.getCriticalChance() << " " << character.getDodgeChance() << " " << character.getExtraExperience() << " " << character.getDebt() << " " << game.getTotalScore() << " " << game.getTotalScore();
		ilkKayit.close();
	}
	else { // �nceden kay�t varsa
		ifstream kayitOku("Save.txt", ios::in);
		ofstream kayitYaz("Save1.txt", ios::app);
		while (!kayitOku.eof())
		{
			for (int i = 0; i < 20; i++) // Kay�t okuma
				kayitOku >> Okunan[i];
			if (gelenKayitNo == Okunan[0]) { // Kay�t g�ncelleme
				kayitYaz << "\n" << gelenKayitNo << " " << character.getLevel() << " " << character.getExperience() << " " << character.getHealt() << " " << character.getMaxHealt() << " " << character.getAttack() << " " << character.getGold() << " " << character.getStatusScore() << " " << pet.getLevel() << " " << pet.getExperience() << " " << firstAid.getEffect() << " " << firstAid.getCount() << " " << grenade.getEffect() << " " << grenade.getCount() << " " << character.getCriticalChance() << " " << character.getDodgeChance() << " " << character.getExtraExperience() << " " << character.getDebt() << " " << game.getTotalScore();
				if (game.getTotalScore() >= game.getReadHiScore())
					kayitYaz << " " << game.getHiScore();
				else if (game.getTotalScore() < game.getReadHiScore())
					kayitYaz << " " << game.getReadHiScore();
				gecici = 1;
			}
			else { //Dosyadaki kay�t numaralar�yla gelenKayitNo aras�nda e�le�en de�er yoksa
				kayitYaz << "\n";
				for (int i = 0; i < 19; i++)
					kayitYaz << Okunan[i] << " ";
				if (game.getTotalScore() >= game.getReadHiScore())
					kayitYaz << game.getHiScore();
				else if (game.getTotalScore() < game.getReadHiScore())
					kayitYaz << game.getReadHiScore();
			}
		}
		if (gecici == 0) { //yeni kay�t a�ma
			kayitYaz << "\n" << gelenKayitNo << " " << character.getLevel() << " " << character.getExperience() << " " << character.getHealt() << " " << character.getMaxHealt() << " " << character.getAttack() << " " << character.getGold() << " " << character.getStatusScore() << " " << pet.getLevel() << " " << pet.getExperience() << " " << firstAid.getEffect() << " " << firstAid.getCount() << " " << grenade.getEffect() << " " << grenade.getCount() << " " << character.getCriticalChance() << " " << character.getDodgeChance() << " " << character.getExtraExperience() << " " << character.getDebt() << " " << game.getTotalScore();
			if (game.getTotalScore() >= game.getReadHiScore())
				kayitYaz << " " << game.getHiScore();
			else if (game.getTotalScore() < game.getReadHiScore())
				kayitYaz << " " << game.getReadHiScore();
		}
		hizala(1, 6); cout << "Kay�t i�lemi ba�ar�yla ger�ekle�tirildi."; Sleep(1000);
		kayitOku.close();
		kayitYaz.close();
		remove("Save.txt");
		rename("Save1.txt", "Save.txt");
	}
	oyunmenu();
}
void dosyakayitOku(int gelenKayitSecim) {
	Temp temp{};
	ifstream kayitOku("Save.txt", ios::in);
	for (int i = 0; i < gelenKayitSecim; i++)
		kayitOku >> KayitNo >> temp.level >> temp.experience >> temp.healt >> temp.maxHealt >> temp.attack >> temp.gold >> temp.statusScore >> temp.petLevel >> temp.petExperience >> temp.firstAidEffect >> temp.firstAidCount >> temp.grenadeEffect >> temp.grenadeCount >> temp.criticalChance >> temp.dodgeChance >> temp.extraExperience >> temp.debt >> temp.totalScore >> temp.hiScore;
	kayitOku.close();

	character.setFullVariable(temp.healt, temp.maxHealt, temp.attack, temp.gold, temp.level, temp.experience, temp.statusScore, temp.criticalChance, temp.extraExperience, temp.dodgeChance, temp.debt);
	pet.setFullVariable(temp.petLevel, temp.petExperience);
	firstAid.setFullVariable(temp.firstAidEffect, temp.firstAidCount);
	grenade.setFullVariable(temp.grenadeEffect, temp.grenadeCount);
	game.setFullVariable(temp.totalScore, temp.hiScore);

	oyunmenu();
}
int hiscoreOku() {
	int OkunanHiscore, skorKarsilastir = 0, sayac = 0;
	ifstream rasgeleKayitOku("Save.txt", ios::in);
	if (!rasgeleKayitOku || rasgeleKayitOku.tellg() == 0) //Dosya Kontrol�
		skorKarsilastir = 0;
	else {
		while (!rasgeleKayitOku.eof())
		{
			for (int i = 0; i < 20; i++)
				rasgeleKayitOku >> OkunanHiscore;
			sayac++;
			if (sayac == 1) // Okunan ilk de�eri skorKarsilastir'a at sonrakileri ona g�re kar��la�t�r
				skorKarsilastir = OkunanHiscore;
			if (OkunanHiscore > skorKarsilastir)
				skorKarsilastir = OkunanHiscore;
		}
	}
	rasgeleKayitOku.close();
	return skorKarsilastir;
}

int main() {
	setlocale(LC_ALL, "Turkish");
	srand(time_t(NULL));
	hizala(13, 5); harfOku(message.welcomeGame, message.welcomeGame.length());	Sleep(1000);
	hosgeldiniz();
	anamenu();
}