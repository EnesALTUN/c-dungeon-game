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
	hizala(2, 6); cout << "    Ana Menü"; hizala(1, 6); cout << "-------------------"; hizala(2, 6); cout << "1) Yeni Oyuna Baþla"; hizala(1, 6); cout << "2) Kayýtlý Oyunlar"; hizala(1, 6); cout << "3) Yapýmcý"; hizala(1, 6); cout << "4) Yardým"; hizala(1, 6); cout << "5) Oyundan Çýk";
	hizala(2, 6); cout << "Ne yapmak istiyorsunuz ? : "; cin >> secimmenu;
	switch (secimmenu) {
	case 1:
		zorluk();
		break;
	case 2:
		if (!kayitSayacOku || kayitSayacOku.tellg() == 0) {
			hizala(1, 6);	cout << "!! Kayýtlý oyun bulunamadý. !!";
		}
		else
			savemenu();
		break;
	case 3:
		hizala(1, 5);
		harfOku(message.producer, message.producer.length());
		break;
	case 4:
		hizala(1, 5); cout << "Oyun zindan temizleyip güçlenme üzerine kurulu bir oyundur."; hizala(1, 5); cout << "Oyundan çýkarsanýz mevcut ilerlemeniz kaydedilmeyecektir!"; hizala(1, 5); cout << "10 Levele ulaþtýðýnýzda bir adet pet seçmeniz gerekecek.";
		Sleep(1000);
		break;
	case 5:
		hizala(1, 6); harfOku(message.seeYou, message.seeYou.length());
		Sleep(500);
		exit(0);
		break;
	default:
		hizala(1, 6);
		cout << "!! Yanlýþ giriþ yaptýnýz. !!";
		break;
	}
	Sleep(2000);
	anamenu();
}
void zorluk() {
	int zorluksecim;
	system("cls");
	hosgeldiniz();
	hizala(2, 6); cout << " Zorluk Menüsü"; hizala(1, 6); cout << "---------------"; hizala(2, 6); cout << "1) Kolay"; hizala(1, 6); cout << "2) Orta"; hizala(1, 6); cout << "3) Zor\n";
	hizala(1, 6); cout << "Oyun zorluðunu seçin : ";	cin >> zorluksecim;
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
		cout << "!! Yanlýþ giriþ yaptýnýz. !!";
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
	hizala(1, 6); cout << "Karakter Seçim Menüsü"; hizala(1, 6); cout << "---------------------";
	hizala(2, 2); cout << "    1) Geralth \t\t    2) Cirilla \t\t    3) Yennefer \t    4) Vesemir"; hizala(1, 2); cout << "-------------------\t-------------------\t-------------------\t-------------------";
	hizala(1, 2); cout << "> Can  : " << character.getHealt() + 250 << "\t\t> Can  : " << character.getHealt() + 450 << "\t\t> Can  : " << character.getHealt() + 100 << "\t\t> Can  : " << character.getHealt() + 450;
	hizala(1, 2); cout << "> Atak : " << character.getAttack() + 50 << "\t\t> Atak : " << character.getAttack() + 20 << "\t\t> Atak : " << character.getAttack() + 100 << "\t\t> Atak : " << character.getAttack() + 20;
	hizala(1, 2); cout << "> Ýlk Yardým : +" << firstAid.getEffect() + 150 << "\t> Ýlk Yardým : +" << firstAid.getEffect() + 300 << "\t> Ýlk Yardým : +" << firstAid.getEffect() + 50 << "\t> Ýlk Yardým : +" << firstAid.getEffect() + 150;
	hizala(1, 2); cout << "> Bomba Hasar : " << grenade.getEffect() + 175 << "\t> Bomba Hasar : " << grenade.getEffect() + 100 << "\t> Bomba Hasar : " << grenade.getEffect() + 300 << "\t> Bomba Hasar : " << grenade.getEffect() + 175;

	hizala(2, 6); cout << "Seçmek istediðiniz karakter ? : ";	cin >> karaktersecim;
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
		cout << "!! Yanlýþ giriþ yaptýnýz. !!";
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
	hizala(1, 6); cout << "Pet Seçim Menüsü"; hizala(1, 6); cout << "----------------";
	hizala(2, 2); cout << "  1) Yavru Aslan \t  2) Yavru Maymun \t  3) Yavru Örümcek \t  4) Yavru Akrep"; hizala(1, 2); cout << "-------------------\t-------------------\t-------------------\t-------------------";
	hizala(1, 2); cout << "> Can  : " << character.getMaxHealt() + 250 << "\t\t> Can  : " << character.getMaxHealt() + 450 << "\t\t> Can  : " << character.getMaxHealt() + 100 << "\t\t> Can  : " << character.getMaxHealt() + 250;
	hizala(1, 2); cout << "> Atak : " << character.getAttack() + 100 << "\t\t> Atak : " << character.getAttack() + 20 << "\t\t> Atak : " << character.getAttack() + 50 << "\t\t> Atak : " << character.getAttack() + 100;
	hizala(1, 2); cout << "> Tecrübe : +" << character.getExtraExperience() + 100 << "\t> Tecrübe : +" << character.getExtraExperience() + 200 << "\t> Tecrübe : +" << character.getExtraExperience() + 300 << "\t> Tecrübe : +" << character.getExtraExperience() + 300;
	if (character.getCriticalChance() < 75) {
		hizala(1, 2); cout << "> Kritik Þansý : " << character.getCriticalChance() + 15 << "\t> Kritik Þansý : " << character.getCriticalChance() + 15 << "\t> Kritik Þansý : " << character.getCriticalChance() + 25 << "\t> Kritik Þansý : " << character.getCriticalChance() + 25;
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
		cout << "!! Yanlýþ giriþ yaptýnýz. !!";
		Sleep(1500);
		petsecme();
		break;
	}
	return 0;
	oyunmenu();
}
void karakterstatu() {
	int statumenu;
	game.setReadHiScore(hiscoreOku()); //Dosyada kayýt varsa en yüksek skoru al, kayýt yoksa þu anki skoru al
	system("cls");
	hosgeldiniz();
	system("COLOR 3");
	hizala(2, 6); cout << "Karakter Statüleri"; hizala(1, 6); cout << "------------------";
	hizala(1, 5); cout << "Toplam Skor : " << game.getTotalScore(); if (game.getTotalScore() > game.getHiScore()) { game.setHiScore(game.getTotalScore()); } cout << "\t Yüksek Skor : "; (game.getHiScore() > game.getReadHiScore()) ? (cout << game.getHiScore()) : (cout << game.getReadHiScore());
	hizala(2, 6); cout << "> Level : " << character.getLevel(); hizala(1, 6); cout << "> Tecrübe : " << character.getExperience() << " / " << (character.getLevel() * 50); hizala(1, 6); cout << "> Can   : " << character.getHealt() << " / " << character.getMaxHealt(); hizala(1, 6); cout << "> Atak  : " << character.getAttack(); hizala(1, 6); cout << "> Altýn : " << character.getGold(); hizala(1, 6); cout << "> Kritik Þansý : % " << character.getCriticalChance(); hizala(1, 6); cout << "> Dodge Þansý : % " << character.getDodgeChance();	if (character.getLevel() >= 10) { hizala(1, 6); cout << "> Pet Level : " << pet.getLevel(); hizala(1, 6); cout << "> Pet Tecrübe : " << pet.getExperience() << " / " << pet.getLevel() * 50; }
	hizala(2, 6); cout << "1) Statü Geliþtir (" << character.getStatusScore() << ")"; hizala(1, 6); cout << "2) Menüye geri dön"; hizala(1, 6); cout << "3) Oyundan Çýk\n";
	hizala(1, 6); cout << "Ne Yapmak Ýstiyorsunuz ? : "; cin >> statumenu;
	switch (statumenu) {
	case 1:
		if (character.getStatusScore() > 0)
			statugelistir();
		else {
			hizala(1, 6);
			cout << "Yeterli statü puanýnýz yok";
			Sleep(1000);
			karakterstatu();
		}
		break;
	case 2:
		oyunmenu();
		break;
	case 3:
		hizala(1, 6);
		cout << "Tekrar görüþmek üzere ";
		Sleep(500);
		exit(0);
		break;
	default:
		hizala(1, 6);
		cout << "!! Yanlýþ giriþ yaptýnýz. !!";
		Sleep(1000);
		karakterstatu();
		break;
	}
}
void statugelistir() {
	int statusecim;
	hizala(2, 6); cout << "1) Can (+100)"; hizala(1, 6); cout << "2) Atak (+50)"; hizala(1, 6); cout << "3) Kritik Þans (+ %5)"; hizala(1, 6); cout << "4) Dodge (+ %1)";
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
			cout << "% 100 Kritik isabet þansýna ulaþmýþsýnýz.";
			Sleep(1000);
			karakterstatu();
		}
		break;
	case 4:
		if (character.getDodgeChance() <= 29)
			character.setDodgeChance(character.getDodgeChance() + 1);
		else {
			hizala(1, 5);
			cout << "% 30 Dodge þansýna ulaþmýþsýnýz.";
			Sleep(1000);
			karakterstatu();
		}
		break;
	default:
		hizala(1, 6);
		cout << "!! Yanlýþ giriþ yaptýnýz. !!";
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
	if (!KayitOku || KayitOku.tellg() == 0) {//Dosya yoksa veya boþsa alýnacak kayýt
		KayitOku.close();
		save(1);
		oyunmenu();
	}
	else { //Dosya varsa
		while (!KayitOku.eof())
		{
			for (int i = 0; i < 20; i++) {//Kayýt Oku
				KayitOku >> Okunan[i];
				if (i == 0) { //Kayýt numaralarýný al
					OkunanKarsilastir[karsilastirSayac] = Okunan[0];
					karsilastirSayac++;
				}
			}
			hizala(1, 6); cout << "Kayýt " << Okunan[0] << ")" << " Karakter Level : " << Okunan[1];
			sayac++;
			if (sayac == 1) //ilk döngüde okunanmax deðerine ilk okunan deðer atandý
				okunanMax = Okunan[0];
			if (Okunan[0] > okunanMax) //okunan deðerlerden max olaný araþtýrýldý
				okunanMax = Okunan[0];
		}
		KayitOku.close();
		hizala(2, 6); cout << "1) Yeni Kayýt"; hizala(1, 6); cout << "2) Kayýt Üzerine Yaz"; hizala(1, 6); cout << "3) Menüye Geri Dön";
		hizala(2, 6); cout << "Ne yapmak istiyorsunuz ? : "; cin >> kayitseccevap;
		if (kayitseccevap == 1) { //Yeni Kayýt
			okunanMax++;
			KayitOku.close();
			save(okunanMax);
		}
		else if (kayitseccevap == 2) { //Kayýt üzerine
			int dogrugiris = 0;
			hizala(1, 6); cout << "Hangi kaydýn üzerine kaydedilsin ? : ";	cin >> kayitsecim;
			for (int i = 0; i < karsilastirSayac; i++) {
				if (kayitsecim == OkunanKarsilastir[i]) { //Dosyadaki kayýtlardan birini seçerse
					dogrugiris = 1;
					KayitOku.close();
					save(kayitsecim);
				}
			}
			if (dogrugiris == 0) { //Dosyadaki kayýtlardan herhangi birini seçmezse
				system("cls");
				hosgeldiniz();
				kayitListele();
			}
		}
		else if (kayitseccevap == 3)
			oyunmenu();
		else {
			hizala(1, 6);
			cout << "!! Yanlýþ giriþ yaptýnýz. !!";
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
		if (silinecekKayit == temp.saveNo) {//Gelen numara dosyadan okunan numarayla eþleþirse kaydý dosyaya yazma
			hizala(1, 6); cout << "Silme iþlemi baþarýyla gerçekleþtirildi.";
			Sleep(1000);
			gecici = 1;
		}
		else { //eþleþen numara yoksa okunan kaydý dosyaya yaz
			KayitYaz << "\n" << temp.saveNo << " " << temp.level << " " << temp.experience << " " << temp.healt << " " << temp.maxHealt << " " << temp.attack << " " << temp.gold << " " << temp.statusScore << " " << temp.petLevel << " " << temp.petExperience << " " << temp.firstAidEffect << " " << temp.firstAidCount << " " << temp.grenadeEffect << " " << temp.grenadeCount << " " << temp.criticalChance << " " << temp.dodgeChance << " " << temp.extraExperience << " " << temp.debt << " " << temp.totalScore << " " << temp.hiScore;
			gecici = 2;
		}
	}
	if (gecici == 0) //Dosya boþsa
		cout << "Dosyada Kayýt yok";
	KayitOku.close();
	KayitYaz.close();
	remove("Save.txt");
	rename("Save1.txt", "Save.txt");

	ifstream Kayitsiz("Save.txt", ios::in);
	Kayitsiz.close();
	if (helper.is_empty(Kayitsiz)) //Dosyada kayýt yoksa sil ()
		remove("Save.txt");

	oyunmenu();
}

void oyunmenu() {
	int oyunmenusecim, Okunan[20] = {}, silKayit;
	ifstream KayitOku("Save.txt", ios::in); //Switch case in her seçimi için dosya açýk kalmasýn diye kapatmak gerekiyor. !!
	system("cls");
	hosgeldiniz();
	hizala(2, 6); cout << "   Oyun Menüsü"; hizala(1, 6); cout << "-----------------"; hizala(2, 6); cout << "1) Karakter Statü (" << character.getStatusScore() << ")"; hizala(1, 6); cout << "2) Envanter"; hizala(1, 6); cout << "3) Maðaza"; hizala(1, 6); cout << "4) Banka"; hizala(1, 6); cout << "5) Zindanlar"; hizala(1, 6); cout << "6) Oyunu Kaydet"; hizala(1, 6); cout << "7) Kayýtlý Oyunu Sil"; hizala(1, 6); cout << "8) Oyundan Çýk\n";
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
			hizala(1, 5); cout << "    Ýlk yardým çantasý kullanmanýz gerekiyor.";
			Sleep(1500);
			oyunmenu();
		}
		break;
	case 6:
		KayitOku.close();
		kayitListele();
		break;
	case 7:
		if (helper.is_empty(KayitOku)) {//Dosya boþsa
			hizala(1, 6); cout << "Kayýt Bulunamadý";	Sleep(1000);
			KayitOku.close();
			remove("Save.txt");
			oyunmenu();
		}
		while (!KayitOku.eof())
		{
			for (int i = 0; i < 20; i++) //Kayýt oku
				KayitOku >> Okunan[i];
			hizala(1, 6); cout << "Kayýt " << Okunan[0] << ") Karakter Level : " << Okunan[1];
		}
		hizala(1, 6); cout << Okunan[0] + 1 << ") Vazgeç";
		KayitOku.close();
		hizala(2, 6); cout << "Hangi kaydý silmek istiyorsunuz ? : ";	cin >> silKayit;
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
		hizala(1, 6); cout << "!! Yanlýþ giriþ yaptýnýz. !!";
		Sleep(1000);
		oyunmenu();
		break;
	}
}
int esyakullan(int rakipcani) {
	int esyakullan;
	if (firstAid.getCount() > 0 || grenade.getCount() > 0) {
		hizala(1, 6); cout << "1) Ýlk yardým çantasý (+" << firstAid.getEffect() << " Can)"; hizala(1, 6); cout << "2) El bombasý (" << grenade.getEffect() << " Hasar)"; hizala(1, 6); cout << "3) Vazgeç\n"; hizala(1, 6); cout << "Ne yapmak istiyorsunuz ? : "; cin >> esyakullan;
		switch (esyakullan) {
		case 1:
			if (firstAid.getCount() > 0 && (character.getHealt() != character.getMaxHealt())) {
				character.setHealt(character.getHealt() + firstAid.getEffect());
				if (character.getHealt() > character.getMaxHealt())
					character.setHealt(character.getMaxHealt());
				firstAid.setCount(firstAid.getCount() - 1);
			}
			else if (firstAid.getCount() > 0 && (character.getHealt() == character.getMaxHealt())) {
				hizala(1, 5); cout << "Ýlk yardým çantasýna ihtiyacýn yok gibi görünüyor.";
				Sleep(1000);
			}
			else {
				hizala(1, 3); cout << "Malesef elinizde ilk yardým çantasý bulunmuyor. Maðazaya giderek satýn alabilirsiniz.";
				Sleep(1000);
			}
			break;
		case 2:
			if (grenade.getCount() > 0) {
				rakipcani -= grenade.getEffect();
				grenade.setCount(grenade.getCount() - 1);
				if (rakipcani < 0) {
					cout << "Tebrikler zindaný baþarýyla tamamlayarak 200 altýn kazandýnýz.";
					character.setGold(character.getGold() + 200);
				}
			}
			else {
				hizala(1, 4); cout << "Malesef elinizde el bombasý bulunmuyor. Maðazaya giderek satýn alabilirsiniz.";
				Sleep(1000);
			}
			break;
		case 3:
			return rakipcani;
			break;
		default:
			hizala(1, 6); cout << "!! Yanlýþ giriþ yaptýnýz. !!";
			Sleep(1000);
			break;
		}
	}
	else {
		hizala(1, 4); cout << "Malesef envanterinizde kullanýlacak hiçbir öðe bulunmuyor.";
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
		hizala(1, 6); cout << "> Ýlk Yardým : " << firstAid.getCount();
	}
	if (grenade.getCount() > 0) {
		hizala(1, 6); cout << "> El Bombasý : " << grenade.getCount();
	}
	hizala(2, 6); cout << "1) Menüye Geri Dön"; hizala(2, 6); cout << "Ne Yapmak Ýstiyorsunuz : "; cin >> envantersecim;
	switch (envantersecim) {
	case 1:
		oyunmenu();
		break;
	default:
		hizala(1, 6);
		cout << "!! Yanlýþ giriþ yaptýnýz. !!";
		Sleep(1000);
		envanter();
		break;
	}
}
void magaza() {
	int magazasecim;
	system("cls");
	hosgeldiniz();
	hizala(1, 6); cout << "      Maðaza"; hizala(1, 6); cout << "------------------"; hizala(1, 6); cout << "Paranýz : " << character.getGold(); hizala(2, 6); cout << "1) Ýlk yardým çantasý \t> 100 Altýn"; hizala(1, 6); cout << "2) El bombasý \t\t> 150 Altýn"; hizala(1, 6); cout << "3) Menüye geri dön";
	hizala(2, 6); cout << "Ne satýn almak istiyorsunuz ? : ";	cin >> magazasecim;
	switch (magazasecim) {
	case 1:
		if (character.getGold() >= firstAid.getCost()) {
			firstAid.setCount(firstAid.getCount() + 1);
			character.setGold(character.getGold() - firstAid.getCost());
		}
		else {
			hizala(1, 6); cout << "Üzgünüz.. Yeterli altýnýnýz yok.";
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
			hizala(1, 6); cout << "Üzgünüz.. Yeterli altýnýnýz yok.";
			Sleep(2000);
		}
		magaza();
		break;
	case 3:
		oyunmenu();
		break;
	default:
		hizala(1, 6); cout << "!! Yanlýþ giriþ yaptýnýz. !!";
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
	hizala(1, 6); cout << "       Banka"; hizala(1, 6); cout << "    -----------"; hizala(1, 6); cout << "Altýnýnýz : " << character.getGold() << "   Borcunuz : " << character.getDebt(); hizala(2, 6);
	cout << sayac << ") Altýn al"; sayac++;
	if (character.getDebt() > 0) {
		hizala(1, 6); cout << sayac << ") Borç öde"; sayac++;
	}
	hizala(1, 6); cout << sayac << ") Bankadan çýk";
	hizala(2, 6); cout << "Ne yapmak istiyorsunuz ? : "; cin >> bankasecim;
	if (bankasecim == 1) {
		hizala(1, 6); cout << "1) +250 Altýn (%20 Faiz)"; hizala(1, 6); cout << "2) +500 Altýn (%20 Faiz)"; hizala(1, 6); cout << "3) +1000 Altýn (%20 Faiz)"; hizala(1, 6); cout << "4) Vazgeç\n";
		hizala(1, 6); cout << "Ne yapmak istiyorsunuz ? : "; cin >> alimsecim;
		hizala(1, 6);
		switch (alimsecim) {
		case 1:
			character.setGold(character.getGold() + 250);
			character.setDebt(character.getDebt() + 250 * 1.2);
			cout << "Hesabýnýza 250 Altýn baþarýyla yatýrýlmýþtýr.";
			break;
		case 2:
			character.setGold(character.getGold() + 500);
			character.setDebt(character.getDebt() + 500 * 1.2);
			cout << "Hesabýnýza 500 Altýn baþarýyla yatýrýlmýþtýr.";
			break;
		case 3:
			character.setGold(character.getGold() + 1000);
			character.setDebt(character.getDebt() + 1000 * 1.2);
			cout << "Hesabýnýza 1000 Altýn baþarýyla yatýrýlmýþtýr.";
			break;
		case 4:
			banka();
			break;
		default:
			cout << "!! Yanlýþ giriþ yaptýnýz. !! \n";
			Sleep(1500);
			banka();
			break;
		}
	}
	else if (character.getDebt() > 0 && bankasecim == 2) {
		hizala(2, 6); cout << "Ne kadar ödemek istiyorsunuz : ";	cin >> borcode;
		if (borcode <= character.getDebt()) {
			hizala(1, 3); cout << character.getDebt() << " Altýn olan borcunuzun " << borcode << " Altýn kadarýný ödeyeceksiniz. Onaylýyor musunuz ? (E / H) : ";	cin >> borcodeonay;
			switch (borcodeonay) {
			case 'E':
			case 'e':
				if (character.getGold() >= borcode) {
					character.setDebt(character.getDebt() - borcode);
					character.setGold(character.getGold() - borcode);
				}
				else {
					cout << "Üzgünüz. Hesabýnýzda yeterli altýn bulunmamaktadýr.";
					Sleep(1500);
				}
				break;
			case 'H':
			case 'h':
				break;
			default:
				cout << "!! Yanlýþ giriþ yaptýnýz. !!";
				Sleep(1500);
				break;
			}
			banka();
		}
	}
	else if (bankasecim == sayac) //Sayacýn max deðeri girilirse menüye dön
		oyunmenu();
	else {
		hizala(1, 6); cout << "!! Yanlýþ giriþ yaptýnýz. !!";
	}
	Sleep(1500);
	goto bankabas;
}
void zindanlar() {
	int zindansecim;
	system("cls");
	hosgeldiniz();
	hizala(2, 6); cout << "    Zindanlar"; hizala(1, 6); cout << "-----------------"; hizala(2, 6); cout << "1) Örümcek Zindaný (Minimum Lv 1)"; hizala(1, 6); cout << "2) Maymun Zindaný  (Minimum Lv 5)"; hizala(1, 6); cout << "3) Menüye geri dön";
	hizala(2, 6); cout << "Ne yapmak istiyorsunuz ? : "; cin >> zindansecim;
	switch (zindansecim) {
	case 1:
		orumcekzindani();
		break;
	case 2:
		if (character.getLevel() > 5)
			maymunzindani();
		else {
			hizala(1, 6); cout << "Üzgünüz.. Malesef yeterli seviyeye ulaþmamýþsýnýz.";
			Sleep(1500);
			zindanlar();
		}
		break;
	case 3:
		oyunmenu();
		break;
	default:
		hizala(1, 6); cout << "!! Yanlýþ giriþ yaptýnýz. !!";
		Sleep(1000);
		zindanlar();
		break;
	}
}
void orumcekzindani() { //cikissayac zindanda eylem yaparsan ve zindaný bitirmeden çýkarsan ceza
	int zindankarar, cikissayac = 0, raund = 1;
	Mob spider(700, 700, 200, 50);
zindanbas:
	system("cls");
	hosgeldiniz();
	hizala(1, 6); cout << "> ÖRÜMCEK ZÝNDANI <\n\tOyuncunun Statüleri"; hizala(0, 8); cout << "Örümceðin Statüleri\n\t-------------------"; hizala(0, 8); cout << "-------------------\n\t> Can  : " << character.getHealt() << " / " << character.getMaxHealt(); hizala(0, 8); cout << "> Can  : " << spider.getHealt() << " / " << spider.getMaxHealt() << "\n\t> Atak : " << character.getAttack(); hizala(0, 9); cout << "> Atak : " << spider.getAttack() << "\n\t> Sahip Olunanlar \n\t    Ýlk yardým çantasý : " << firstAid.getCount() << "\n\t    El bombasý : " << grenade.getCount();
	if (spider.getHealt() > 0 && character.getHealt() > 0) {
		hizala(1, 7); cout << "Raund < " << raund << " >";
		hizala(2, 5); cout << "1) Atak      2) Eþya kullan \t 3) Zindandan çýk";	hizala(2, 6); cout << "Ne yapmak istiyorsunuz ? : "; cin >> zindankarar;
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
				hizala(1, 4); cout << "Tebrikler zindaný baþarýyla tamamlayarak 200 altýn, " << spider.getExperience() + character.getExtraExperience() << " tecrübe puaný kazandýnýz.";
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
				hizala(1, 6); cout << "100 altýn kaybettiniz.";
				character.setGold(character.getGold() - 100);
				Sleep(1000);
			}
			oyunmenu();
			break;
		default:
			hizala(1, 6); cout << "!! Yanlýþ giriþ yaptýnýz. !!";
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
		hizala(1, 4); cout << "Tebrikler zindaný baþarýyla tamamlayarak 200 altýn, " << spider.getExperience() + character.getExtraExperience() << " tecrübe puaný kazandýnýz.";
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
	hizala(1, 6); cout << "    Kayýt Menüsü"; hizala(1, 6); cout << "  ----------------\n";
	ifstream KayitOkuma("Save.txt", ios::in);
	while (!KayitOkuma.eof())
	{
		KayitOkuma >> temp.saveNo >> temp.level >> temp.experience >> temp.healt >> temp.maxHealt >> temp.attack >> temp.gold >> temp.statusScore >> temp.petLevel >> temp.petExperience >> temp.firstAidEffect >> temp.firstAidCount >> temp.grenadeEffect >> temp.grenadeCount >> temp.criticalChance >> temp.dodgeChance >> temp.extraExperience >> temp.debt >> temp.totalScore >> temp.hiScore;
		hizala(1, 6); cout << "Kayýt " << sayac + 1 << ")" << " Karakter Level : " << temp.level;
		sayac++;
	}
	KayitOkuma.close();
	hizala(2, 6); cout << sayac + 1 << ") Ana Menüye Geri Dön" << endl;
	do
	{
		hizala(1, 6); cout << "Hangi kaydý oynamak istiyorsunuz ? : ";	cin >> kayitsecim;
		if (kayitsecim == sayac + 1)
			anamenu();
	} while (kayitsecim <= 0 || kayitsecim > sayac);
	dosyakayitOku(kayitsecim);
}
void save(int gelenKayitNo) {
	int Okunan[20]{}, gecici = 0; // ilk while döngüsünde gecici deðeri deðiþmezse yeni kayýt eklendiðini anla
	game.setReadHiScore(hiscoreOku());
	if (gelenKayitNo == 1) {//önceden kayýt yoksa
		ofstream ilkKayit("Save.txt", ios::out);
		ilkKayit << "\n" << gelenKayitNo << " " << character.getLevel() << " " << character.getExperience() << " " << character.getHealt() << " " << character.getMaxHealt() << " " << character.getAttack() << " " << character.getGold() << " " << character.getStatusScore() << " " << pet.getLevel() << " " << pet.getExperience() << " " << firstAid.getEffect() << " " << firstAid.getCount() << " " << grenade.getEffect() << " " << grenade.getCount() << " " << character.getCriticalChance() << " " << character.getDodgeChance() << " " << character.getExtraExperience() << " " << character.getDebt() << " " << game.getTotalScore() << " " << game.getTotalScore();
		ilkKayit.close();
	}
	else { // önceden kayýt varsa
		ifstream kayitOku("Save.txt", ios::in);
		ofstream kayitYaz("Save1.txt", ios::app);
		while (!kayitOku.eof())
		{
			for (int i = 0; i < 20; i++) // Kayýt okuma
				kayitOku >> Okunan[i];
			if (gelenKayitNo == Okunan[0]) { // Kayýt güncelleme
				kayitYaz << "\n" << gelenKayitNo << " " << character.getLevel() << " " << character.getExperience() << " " << character.getHealt() << " " << character.getMaxHealt() << " " << character.getAttack() << " " << character.getGold() << " " << character.getStatusScore() << " " << pet.getLevel() << " " << pet.getExperience() << " " << firstAid.getEffect() << " " << firstAid.getCount() << " " << grenade.getEffect() << " " << grenade.getCount() << " " << character.getCriticalChance() << " " << character.getDodgeChance() << " " << character.getExtraExperience() << " " << character.getDebt() << " " << game.getTotalScore();
				if (game.getTotalScore() >= game.getReadHiScore())
					kayitYaz << " " << game.getHiScore();
				else if (game.getTotalScore() < game.getReadHiScore())
					kayitYaz << " " << game.getReadHiScore();
				gecici = 1;
			}
			else { //Dosyadaki kayýt numaralarýyla gelenKayitNo arasýnda eþleþen deðer yoksa
				kayitYaz << "\n";
				for (int i = 0; i < 19; i++)
					kayitYaz << Okunan[i] << " ";
				if (game.getTotalScore() >= game.getReadHiScore())
					kayitYaz << game.getHiScore();
				else if (game.getTotalScore() < game.getReadHiScore())
					kayitYaz << game.getReadHiScore();
			}
		}
		if (gecici == 0) { //yeni kayýt açma
			kayitYaz << "\n" << gelenKayitNo << " " << character.getLevel() << " " << character.getExperience() << " " << character.getHealt() << " " << character.getMaxHealt() << " " << character.getAttack() << " " << character.getGold() << " " << character.getStatusScore() << " " << pet.getLevel() << " " << pet.getExperience() << " " << firstAid.getEffect() << " " << firstAid.getCount() << " " << grenade.getEffect() << " " << grenade.getCount() << " " << character.getCriticalChance() << " " << character.getDodgeChance() << " " << character.getExtraExperience() << " " << character.getDebt() << " " << game.getTotalScore();
			if (game.getTotalScore() >= game.getReadHiScore())
				kayitYaz << " " << game.getHiScore();
			else if (game.getTotalScore() < game.getReadHiScore())
				kayitYaz << " " << game.getReadHiScore();
		}
		hizala(1, 6); cout << "Kayýt iþlemi baþarýyla gerçekleþtirildi."; Sleep(1000);
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
	if (!rasgeleKayitOku || rasgeleKayitOku.tellg() == 0) //Dosya Kontrolü
		skorKarsilastir = 0;
	else {
		while (!rasgeleKayitOku.eof())
		{
			for (int i = 0; i < 20; i++)
				rasgeleKayitOku >> OkunanHiscore;
			sayac++;
			if (sayac == 1) // Okunan ilk deðeri skorKarsilastir'a at sonrakileri ona göre karþýlaþtýr
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