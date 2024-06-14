#version 330 core

// Pozycje/Wsp�rz�dne
layout (location = 0) in vec3 aPos;
// Kolory
layout (location = 1) in vec3 aColor;
// Wsp�rz�dne tekstury
layout (location = 2) in vec2 aTex;
// Normalne (niekoniecznie znormalizowane)
layout (location = 3) in vec3 aNormal;

// Wyj�cie koloru dla Fragment Shadera
out vec3 color;
// Wyj�cie wsp�rz�dnych tekstury dla Fragment Shadera
out vec2 texCoord;
// Wyj�cie normalnych dla Fragment Shadera
out vec3 Normal;
// Wyj�cie bie��cej pozycji dla Fragment Shadera
out vec3 crntPos;

// Importuje macierz kamery z funkcji g��wnej
uniform mat4 camMatrix;
// Importuje macierz modelu z funkcji g��wnej
uniform mat4 model;

void main()
{
    // Oblicza bie��c� pozycj�
    crntPos = vec3(model * vec4(aPos, 1.0f));
    // Przekazuje pozycje/wsp�rz�dne wszystkich wierzcho�k�w
    gl_Position = camMatrix * vec4(crntPos, 1.0);

    // Przypisuje kolory z danych wierzcho�k�w do "color"
    color = aColor;
    // Przypisuje wsp�rz�dne tekstury z danych wierzcho�k�w do "texCoord"
    texCoord = aTex;
    // Przypisuje normalne z danych wierzcho�k�w do "Normal"
    Normal = aNormal;
}
