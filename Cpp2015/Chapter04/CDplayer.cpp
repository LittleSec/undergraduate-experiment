#include<iostream>
#include<string>
using namespace std;

class CD{
public:
	CD(string name, string song[6]);
	string getsonger() const{
		return songer;
	}

    string getsong(int index) const;
	void listsongs() const;
private:
	string songer;
	string songs[6];
};

CD::CD(string name, string song[6]){
	int i;

	songer = name;
	for(i = 0; i < 6; i++)
		songs[i] = song[i];
}

string CD::getsong(int index) const{
	return songs[index];
}

void CD::listsongs()const{
	int i;

	cout<<"Songer: "<<getsonger()<<endl;
	for(i = 0; i < 6; i++)
        cout<<(i + 1)<<" . "<<getsong(i)<<endl;
}

class CDplayer{
public:
    CDplayer(bool in = false):cdin(in){}
	void showbuttons() const;
	void insertCD(CD* acd);
    void play() const;
    CD* ejectCD();
private:
	bool cdin;
	CD* cd;
};

void CDplayer::showbuttons() const{
	cout<<"****************************"<<endl;
	cout<<"*   1.Play CD              *"<<endl;
	cout<<"*   2.Insert CD            *"<<endl;
	cout<<"*   3.Eject CD             *"<<endl;
	cout<<"*   0.Shutdown             *"<<endl;
	cout<<"****************************"<<endl<<endl;
}

void CDplayer::insertCD(CD* acd){
    cd = acd;
    if(cdin == false){
		 cout<<"Insert "<<cd->getsonger()<<"'s CD......"<<endl<<endl;
		 cout<<"Playing "<<cd->getsonger()<<"'s CD......"<<endl;
		 cout<<"Singer: "<<cd->getsonger()<<endl;
		 cdin=true;
    }
    else
		 cout<<"Please put out the CD firstly."<<endl;
}

CD* CDplayer::ejectCD(){
	if(cdin == true)
		cout<<"Eject "<<cd->getsonger()<<"'s CD"<<"......"<<endl;
	else
	    cout<<"There are no CDs in CD."<<endl;

	cdin = false;
    return (cd = NULL);
}

void CDplayer::play()const{
	int i;
	if(cdin == true){
		for(i = 0; i < 6; i++)
			cout<<(i + 1)<<"."<<cd->getsong(i)<<endl;
	}
 	else
		cout<<"Please insert CD first."<<endl<<endl;
}


int main(){
	string name;
	string songs[6];

	cout<<"Create CD......"<<endl;
	cout<<"Singer's Name: ";
	cin>>name;

	for(int i=0;i<6;i++){
		cout<<" song"<<(i+1)<<"#";
        cin>>songs[i];
    }

	CD cd(name, songs);
	cd.listsongs();
    CDplayer player;
    CD* acd = &cd;

	player.showbuttons();
	player.play();
	player.insertCD(acd);
    player.play();
	player.ejectCD();

	return 0;
}

