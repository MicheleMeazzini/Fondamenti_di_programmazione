#include "compito.h"

int main()
{
    cout << "--- PRIMA PARTE---" << endl;

    cout << "Test del costruttore di default:" << endl;
    MediaPlaylist mp;
    cout << "mp" << endl << mp << endl;

    cout << "Test inserisci:" << endl;
    mp.inserisci("We are the champions", AUDIO);
    mp.inserisci("Another brick in the wall", VIDEO);
    mp.inserisci("Stairway to heaven", AUDIO);
    mp.inserisci("We are the champions", VIDEO);
    mp.inserisci("We are the champions", AUDIO);
    cout << "mp" << endl << mp << endl;

    cout << "Test elimina:" << endl;
    mp.elimina("We are the champions", VIDEO);
    mp.elimina("Stairway to heaven", VIDEO);
    mp.elimina("Bohemian rhapsody", VIDEO);
    cout << "mp" << endl << mp << endl;

    // SECONDA PARTE
    cout << "--- SECONDA PARTE---" << endl;

    cout << "Test costruttore MediaPlaylist(item*, int)" << endl;
    item myItemList[] =
            {
                    {AUDIO, "Michelle"},
                    {VIDEO, "Thriller"}
            };

    MediaPlaylist mp2(myItemList, 2);
    cout << "mp2" << endl << mp2 << endl;

    mp2.inserisci("Smoke on the water", AUDIO);
    mp2.elimina("Michelle",AUDIO);
    cout << "mp2" << endl << mp2 << endl;

    cout << "Test costruttore di copia:" << endl;
    MediaPlaylist mp3 = mp2;
    cout << "mp3" << endl << mp3 << endl;

    mp3.inserisci("Sweet child o' mine", VIDEO);
    cout << "mp3" << endl << mp3 << endl;

    cout << "Test riproduci:" << endl;
    Tipo tipo;
    if (mp3.riproduci("Sweet child o' mine", tipo))
        cout << "Riprodotto file " << ((tipo==AUDIO)?"AUDIO":"VIDEO") << endl;
    else
        cout << "File non presente" << endl;

    if (mp3.riproduci("Smoke on the water", tipo))
        cout << "Riprodotto file " << ((tipo==AUDIO)?"AUDIO":"VIDEO") << endl;
    else
        cout << "File non presente" << endl;

    if (mp3.riproduci("Michelle", tipo))
        cout << "Riprodotto file " << ((tipo==AUDIO)?"AUDIO":"VIDEO") << endl;
    else
        cout << "File non presente" << endl;

    cout << endl << "Test del distruttore" << endl;
    {
        MediaPlaylist mp4(mp3);
        mp4.inserisci("Highway to hell", AUDIO);
        cout << mp4;
    }
    cout << "(mp4 distrutto)" << endl;

    return 0;
}