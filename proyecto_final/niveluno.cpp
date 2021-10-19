#include "niveluno.h"

niveluno::niveluno()
{
    ifstream archivo;
        string coorde,numero,int1,int2,int3,int4,digi;
        int ente1,ente2,ente3,ente4,len,conta;
        archivo.open(ruta, ios::in);
        while(!archivo.eof())
        {
            if (archivo.eof())
                break;
            getline(archivo,coorde);
            len=coorde.length();
            conta=0;
            for (int i=0; i<=len;i++)
            {
                digi=coorde[i];
                if (digi!="," and digi[0]!='\000' )
                {
                    numero+=digi;
                }
                else
                {
                    conta+=1;
                    if(conta==1)
                        int1+=numero;
                    else if(conta==2)
                        int2+=numero;
                    else if(conta==3)
                        int3+=numero;
                    else if(conta==4)
                        int4+=numero;
                    numero.erase();
                }
            }
            ente1=atoi(int1.c_str());
            ente2=atoi(int2.c_str());
            ente3=atoi(int3.c_str());
            ente4=atoi(int4.c_str());
            int1.erase();
            int2.erase();
            int3.erase();
            int4.erase();
            bloq_solidos.append(new solidos(ente1,ente2,ente3,ente4));
            scene->addItem(bloq_solidos.back());
        }
        archivo.close();
}
