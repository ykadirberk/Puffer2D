#include "Animator.h"

Animator::Animator(string tilesetpath, string datapath) {
    anidata = new AnimationData(datapath);
    handled = new sf::Texture();
    if (!handled->loadFromFile(tilesetpath)) { //! Texture dosyadan yüklenir. Bu kod daha sonra değiştirilecek.
    	printf("[LOG] Couldn't load tile texture. \n"); //texture yüklenemezse hata mesajı
	} else {
		printf("[LOG] tile texture loaded. \n"); //texture yüklendi mesajı
	}
    calcsp = new sf::Sprite(*handled, sf::IntRect(0,0, anidata->GetScaleRule().x, anidata->GetScaleRule().y));
}

Animator::~Animator() {
    
}

void Animator::CalculateSprite(string key, double deltatime) {
    if (key != keybackup) {
        timer = 0;
        index = 1;
    }
    keybackup = key;
    if (anidata->at(key)[0].x == 0) {
        calcsp->setTextureRect(sf::IntRect(anidata->at(key)[1].x, anidata->at(key)[1].y, anidata->GetScaleRule().x, anidata->GetScaleRule().y));
    } else {
        timer += deltatime;
        if (timer >= anidata->at(key)[0].x) {
            if (index > anidata->at(key).size()) {
                index = 1;
            } else {
                index++;
            }
            calcsp->setTextureRect(sf::IntRect(anidata->at(key)[index].x, anidata->at(key)[index].y, anidata->GetScaleRule().x, anidata->GetScaleRule().y));
            timer = 0;
        }
    }
}

animator::pair Animator::GetScaleRule() {
    return anidata->GetScaleRule();
}

sf::Sprite* Animator::GetSprite() {
    return calcsp;
}