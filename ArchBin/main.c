#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct {
    
    char descripcion[45];
    
} texto;


void crear()
{
    FILE *arch;
    arch=fopen("Binarios.dat","wb");
    if (arch==NULL)
        exit(1);
    fclose(arch);
    
}


void escribir(){
    
    FILE*arch;
    char letra;
    
    texto tex;
    
    arch = fopen("Binarios.dat", "ab");
    
    
    if(arch==NULL){
        printf("Error! :/ \n");
    }
    else{
        printf("Ingrese lo que quiere escribir\n");
        
        scanf("%s",&tex.descripcion);
        
       
           gets(tex.descripcion);
           
           fflush(stdin);
        
       
            fwrite(&tex, sizeof(texto), 1, arch);
        
       
        fclose(arch);
    }
    
    
    
}

    


void leer()
{
    FILE *arch;
    arch=fopen("Binarios.dat","rb");
    
    if (arch==NULL)
        exit(1);
    
    texto salida;
    
    fread(&salida, sizeof(texto), 1, arch);
    
    while(!feof(arch))
    {
        printf("%s\n", salida.descripcion);
        
        fread(&salida, sizeof(texto), 1, arch);
    
    }
    fclose(arch);
    
}




int main()
{
    int opcion;
    do {
        printf("1 - Crear un archivo binario llamado \"Binarios\"\n");
        printf("2 - Ingresar Texto\n");
        printf("3 - Leer archivo.\n");
        printf("4 - Salir\n");
        printf("Ingrese su opcion: ");
        scanf("%d",&opcion);
        
        if((opcion > 4)||(opcion<=0)){
            
            printf("¡Opcion no valida! :/ \n");
        }
        
        switch (opcion) {
            
            case 1:crear();
                   break;
            case 2:escribir();
                   break;
            case 3:leer();
                   break;
            
            
        }
    } while (opcion!=4);
    
    
    
    
    
    
    return 0;
}