# ifndef duende_h
# define duende_h

typedef struct /* PREENCHER AQUI */ Duende;
typedef struct /* PREENCHER AQUI */ Time;
typedef enum { NAO=0, SIM } ESCALADO;

// Manter como especificado
void lerQuantidade(int*);

// Manter como especificado
Duende *alocaDuendes(int);

// Manter como especificado
Time *alocaTimes(int);

// Manter como especificado
void desalocaDuendes(Duende**);

// Manter como especificado
void desalocaTimes(Time**);

// Manter como especificado
void lerDuendes(Duende*, int);

// Manter como especificado
void escalarTimes(Duende*, Time*, int);

// Manter como especificado
int proximoMaisVelho(Duende*, int);

// Manter como especificado
void printTimes(Time*, int);

# endif