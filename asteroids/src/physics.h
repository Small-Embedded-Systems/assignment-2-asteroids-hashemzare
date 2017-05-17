/*
This header file is for defining how the missiles and asteroids will behave
upon being spawned.
*/

/*Struct for the missiles
	v_x, v_y are the velocity of the missile as it travels
	ttl is how the missiles will travel upon being fired
	struct missile *next is a node in linked list, defining the next 
  missile fired until other action is performed.	
*/
typedef struct missile {
    float x,y;
    float v_x, v_y;
    float ttl;
    struct missile *next;
} node_t;

/*Struct for the asteroid objects
	asteroidV_x, asteroidV_y are the velocity of the asteroids as they travel
	ttl is how the missiles will travel upon being spawned
	struct asteroid *next is a node in linked list, defining the next 
  asteroid that can be spawned on the screen.	
*/
typedef struct asteroid {
    float asteroidX,asteroidY;
    float asteroidV_x, asteroidV_y;
    float asteroidTtl;
    struct asteroid *next;
} asteroid_t;

/*These variables define the ship only*/
extern float originX;
extern float originY;
extern int headingAngle;
extern float headingAngleRadians;
extern float pointX;
extern float pointY;
extern float leftX;
extern float leftY;
extern float rightX;
extern float rightY;
extern double score;
extern struct missile *active;
extern struct asteroid *asteroidactive;
extern int lives;
extern double speed;
extern int shieldhealth;
extern int totalscore;
extern double accel;
extern int timealive;
extern int totaltimealive;
extern int invincibility;
extern const int heapsize;
extern const int asteroidHeapsize;

/*These variables define the physics for the asteroids and missiles*/
void physics(void);
void checkshipasteroids(struct asteroid *c);
void checkmissilesasteroids(struct missile *a, struct asteroid *b);
void update(struct missile *l);
void asteroidupdate(struct asteroid *l);
void wraparound(void);
void time(void);
void strike(struct missile *r);
void strike(struct asteroid *r);
void missile_system(void);
void asteroid_system(void);
void initialise_heap(void);
void initialise_asteroidheap(void);
node_t *allocnode(void);
asteroid_t *asteroidallocnode(void);
void freenode(node_t *n);
void asteroidfreenode(asteroid_t *n);
void initialvalues(void);
