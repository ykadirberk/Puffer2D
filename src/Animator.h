#pragma once
#include <stdio.h>
#include <string>
#include <SFML/Graphics.hpp>
#include "AnimationData.h"
using namespace std;

namespace Puffer {
    class Animator {
        public:
            Animator(string tilesetpath, string datapath);                  
            ~Animator();
            void CalculateSprite(string key, double deltatime);
            animator::pair GetScaleRule();
            sf::Sprite* GetSprite();

            AnimationData* anidata = NULL;
        private:
            string keybackup;
            double timer = 0;
            int index = 1;
            sf::Texture* handled = NULL;
            sf::Sprite* calcsp = NULL;
    };

    /*class TextureBuffer {
        public:
            TextureBuffer();
            ~TextureBuffer();
            bool contains(string path);
            bool get(string path);
            void load(string path);
        private:
            string* key = NULL;
            sf::Texture* values = NULL;
    }Opt;*/
}
