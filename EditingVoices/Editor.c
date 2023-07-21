//Coded by : Mehmet Gönenç
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char* argv[])
{
    typedef struct 
    {
        unsigned FrameSync :  11;   //Frame sync
        unsigned ID :  2;
        unsigned LayerIndex :  2;
        unsigned ProtectBit :  1;
        unsigned BitrateIndex :  4;
        unsigned RateIndex :  2;
        unsigned PaddingBit :  1;
        unsigned PrivateBit :  1;
        unsigned ChannelMode :  2;
        unsigned ModeExtension :  2;
        unsigned CopyrightBit :  1;
        unsigned OriginalBit :  1;
        unsigned Emphasis :  2;
    }MP3HEADER;
    
    FILE *input = fopen(argv[1], "r");

    MP3HEADER buffer_header;
    fread(&buffer_header, sizeof(MP3HEADER), 1, input);
    
    FILE *output = fopen(argv[2], "w");
    fwrite(&buffer_header, sizeof(MP3HEADER), 1, output);
    
    uint8_t buffer;
    fseek(input, 0, SEEK_END);
    fseek(input, -7, SEEK_CUR);
    while (ftell(input) > 32)
    {
        printf("%li\n",ftell(input));
        fread(&buffer, sizeof(uint8_t), 1, input);
        
        fwrite(&buffer,sizeof(uint8_t), 1, output);
        fseek(input, -16, SEEK_CUR);
    }
    
    fclose(input);
    fclose(output);
}