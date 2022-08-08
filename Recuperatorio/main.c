#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char marca[20];
    int tipo;
    float peso;
}eVehiculo;

eVehiculo nuevoVehiculo()
{
    eVehiculo aux={0,"null",0,0};

    return aux;
}

int nuevoVehiculoParam(eVehiculo *pVehiculo, int id, char* marca, int tipo, float peso)
{
    if (id>0&&marca&&tipo>0&&peso>0)
    {
        pVehiculo->id=id;
        strcpy(pVehiculo->marca,marca);
        pVehiculo->tipo=tipo;
        pVehiculo->peso=peso;
    }
    else
    {
        return 0;
    }
    return 1;

}

int main()
{
    FILE *archivo;

    eVehiculo test=nuevoVehiculo();
    nuevoVehiculoParam(&test,1,"Renault",12,12.4);

    printf("id %d\n",test.id);
    printf("marca %s\n",test.marca);
    printf("tipo %d\n",test.tipo);
    printf("peso %f\n",test.peso);


    archivo=fopen("data.txt","w");
    fprintf(archivo,"id: %d\nmarca: %10s\ntipo: %d\npeso: %.2f\n",test.id,test.marca,test.tipo,test.peso);
    fclose(archivo);

    //archivo=fopen("data.txt","wb");
    //fwrite();
    //fclose(archivo);


    return 0;
}
