#include "Animator.h"

Animator::Animator(string tilesetpath, string datapath) {
    anidata = new AnimationData(datapath);
    handled = new sf::Texture();
    if (!handled->loadFromFile(tilesetpath)) { //! Texture read from file. Will be changed later
    	printf("[LOG] Couldn't load tile texture. \n"); //Message if file doesn't load.
	} else {
		printf("[LOG] tile texture loaded. \n"); //Message if file loads.
	}
    calcsp = new sf::Sprite(*handled, sf::IntRect(0,0, anidata->GetScaleRule().x, anidata->GetScaleRule().y)); //
}

Animator::~Animator() {
    
}

void Animator::CalculateSprite(string key, double deltatime) {
    //This condition checks if the animation is changed, so that it can reset timer and index variables.
    if (key != keybackup) {
        timer = 0;
        index = 1;
    }
    keybackup = key;

    //If key[0], which is the timer index, is 0 that means there will be no animation. So the animation timer will not be used onwards.
    if (anidata->at(key)[0].x == 0) {
        calcsp->setTextureRect(sf::IntRect(anidata->at(key)[1].x, anidata->at(key)[1].y, anidata->GetScaleRule().x, anidata->GetScaleRule().y));
    } else {
        timer += deltatime;
        if (timer >= anidata->at(key)[0].x) {
            if (index == anidata->at(key).size() - 1) {
                index = 1;
            } else {
                index++;
            }
            timer = 0;
        }
        calcsp->setTextureRect(sf::IntRect(anidata->at(key)[index].x, anidata->at(key)[index].y, anidata->GetScaleRule().x, anidata->GetScaleRule().y));
    }
}

animator::pair Animator::GetScaleRule() {
    return anidata->GetScaleRule();
}

sf::Sprite* Animator::GetSprite() {
    return calcsp;
}