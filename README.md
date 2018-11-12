# ISI_TP2

## Modélisation des objets 

- [x] Corner Cube
- [x] Disk
- [x] Disk Hole
- [x] Cylinder
- [x] Cone
- [ ] Sphere
- [ ] Torus

## Illumination des objets

- [x] Fonctions ComputeNormalsV & ComputeNormalsT fonctionnelles
- [ ] Illumination smooth fonctionnelle

### Modélisation par discrétisatioin d'une fonction math

- [ ] Créer la classe FuncSurface
- [ ] Prototype : 

```c++
FuncSurface::FuncSurface(int nbx, int nby, float minx, float maxx, float miny, float maxy);
```

- [ ] **BONUS** : Ajouter dans le constructeur un pointeur vers la fonction func_expos

```c++
float func_expcos(float x, float y) {
    return exp(-(x*x/2+y*y/2))*cos(2*x*x+2*y*y);
}
```

- [ ] **BONUS** : Ajouter une autre fonction mathématique

## Les fichiers