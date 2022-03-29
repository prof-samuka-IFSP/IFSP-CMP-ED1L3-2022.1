
typedef struct float_vector FloatVector;


// aloque/crie uma struct do tipo FloatVector
FloatVector *create(int capacity);
void destroy(FloatVector **vet_ref);

int capacity(const FloatVector *vet);
int size(const FloatVector *vet);

void append(FloatVector *vet, float val);

void print(const FloatVector *vet);
