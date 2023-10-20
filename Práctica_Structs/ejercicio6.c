#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    unsigned char R, G, B; //componentes primarios de un color
} RGB;

typedef struct
{
    int ancho, alto;
    RGB **pixel;
} ImagenRGB;

typedef unsigned char Gris;

typedef struct
{
    int ancho, alto;
    Gris **pixel;       
} ImagenGris;

ImagenRGB * creaImagenRGB( int , int  );
ImagenGris * creaImagenGris( int , int);
void setPixelRGB( ImagenRGB *, int, int, RGB *);
void setPixelGris( ImagenGris *, int , int , Gris *);
RGB * getPixelRGB( ImagenRGB *, int, int);
Gris *getPixelGris(ImagenGris *, int, int);
void destruyeImagenRGB( ImagenRGB *);
void destruyeImagenGris(ImagenGris *);
Gris RGBtoGris(RGB *);
ImagenGris * transforma( ImagenRGB *);

int main()
{
    int ancho = 100; // Ancho de la imagen
    int alto = 100;  // Alto de la imagen

    // Crear una imagen RGB
    ImagenRGB *imagenRGB = creaImagenRGB(ancho, alto);

    // Asignar valores a los píxeles RGB (ejemplo)
    RGB pixelRojo = {255, 0, 0};
    setPixelRGB(imagenRGB, 0, 0, &pixelRojo);

    // Transformar la imagen RGB en una imagen de escala de grises
    ImagenGris *imagenGris = transforma(imagenRGB);

    // Acceder y mostrar un píxel de la imagen de escala de grises (ejemplo)
    Gris *pixel = getPixelGris(imagenGris, 0, 0);
    printf("Valor de escala de grises en (0, 0): %d\n", *pixel);

    // Liberar memoria de las imágenes
    destruyeImagenRGB(imagenRGB);
    destruyeImagenGris(imagenGris);


    return EXIT_SUCCESS;
}

/* crea y retorna una nueva ImagenRGB */
ImagenRGB * creaImagenRGB( int ancho, int alto )
{
    ImagenRGB *imagen = malloc(sizeof(ImagenRGB));
    imagen->ancho = ancho;
    imagen->alto  = alto;
    imagen->pixel = malloc (sizeof(RGB *)* alto);
    for (int i = 0; i < alto; i++)
    {
        imagen->pixel[i] = malloc(sizeof(RGB ) * ancho);
    }
    
    return imagen;

}

/* crea y retorna una nueva ImagenGris */
ImagenGris * creaImagenGris( int ancho, int alto)
{
    ImagenGris *imagenG = malloc (sizeof(ImagenGris));
    imagenG->alto = alto;
    imagenG->ancho = ancho;
    imagenG->pixel = malloc(sizeof(Gris*) * alto);
    for (int i = 0; i < alto; i++)
    {
        imagenG->pixel[i] = malloc(sizeof(Gris)*ancho);
    }

    return imagenG;
     
}

/* asigna el pixel de la fila y columna dadas */
void setPixelRGB( ImagenRGB *im, int fila, int columna, RGB * pix)
{
    im->pixel[fila][columna] = *pix;

}

/* asigna el pixel de la fila y columna dadas */
void setPixelGris( ImagenGris *im, int fila, int columna, Gris * pix )
{
    im->pixel[fila][columna] = *pix;
}

/* retorna el pixel de la fila y columna dadas */
RGB * getPixelRGB( ImagenRGB *im, int fila, int columna )
{
    return &im->pixel[fila][columna];

}

/* retorna el pixel de la fila y columna dadas */
Gris *getPixelGris(ImagenGris *im, int fila, int columna)
{
    return &im->pixel[fila][columna];
}

/* libera la memoria asociada con la imagen im */
void destruyeImagenRGB( ImagenRGB * im)
{
    for (int i = 0; i < im->alto; i++)
    {
        free(im->pixel[i]);
    }
    free(im->pixel);
    free(im);
}

void destruyeImagenGris(ImagenGris *im)
{
    for (int i = 0; i < im->alto; i++)
        free(im->pixel[i]);
    free(im->pixel);
    free(im);
}

/* convierte un pixel RGB en uno Gris usando la fórmula:
Gris = 0.299*R+0.587*G+0.114*B */
Gris RGBtoGris(RGB *pix)
{
    return 0.299 * pix->R + 0.587 * pix->G + 0.114 * pix->B;
}

/* transforma la imagenRGB en una nueva ImagenGris */
ImagenGris * transforma( ImagenRGB * im )
{
    ImagenGris *imagen = creaImagenGris(im->ancho, im->alto);
    for (int i = 0; i < im->alto; i++)
        for (int j = 0; j < im->ancho; j++)
            imagen->pixel[i][j] = RGBtoGris(&im->pixel[i][j]);
    return imagen;
}