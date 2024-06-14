#version 330 core

// Pozycje/Wspó³rzêdne
layout (location = 0) in vec3 aPos;
// Kolory
layout (location = 1) in vec3 aColor;
// Wspó³rzêdne tekstury
layout (location = 2) in vec2 aTex;
// Normalne (niekoniecznie znormalizowane)
layout (location = 3) in vec3 aNormal;

// Wyjœcie koloru dla Fragment Shadera
out vec3 color;
// Wyjœcie wspó³rzêdnych tekstury dla Fragment Shadera
out vec2 texCoord;
// Wyjœcie normalnych dla Fragment Shadera
out vec3 Normal;
// Wyjœcie bie¿¹cej pozycji dla Fragment Shadera
out vec3 crntPos;

// Importuje macierz kamery z funkcji g³ównej
uniform mat4 camMatrix;
// Importuje macierz modelu z funkcji g³ównej
uniform mat4 model;

void main()
{
    // Oblicza bie¿¹c¹ pozycjê
    crntPos = vec3(model * vec4(aPos, 1.0f));
    // Przekazuje pozycje/wspó³rzêdne wszystkich wierzcho³ków
    gl_Position = camMatrix * vec4(crntPos, 1.0);

    // Przypisuje kolory z danych wierzcho³ków do "color"
    color = aColor;
    // Przypisuje wspó³rzêdne tekstury z danych wierzcho³ków do "texCoord"
    texCoord = aTex;
    // Przypisuje normalne z danych wierzcho³ków do "Normal"
    Normal = aNormal;
}
