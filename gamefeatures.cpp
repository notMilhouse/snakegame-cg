class GamePos {
    public:
        GamePos() {
            posX = 15;
            posY = 15;
        }

        GamePos(int x, int y) {
            posX = x;
            posY = y;
        }

        void setPos(int x, int y) {
            posX = x;
            posY = y;
        }

        int getX() {
            return posX;
        }

        int getY() {
            return posY;
        }

        GamePos* incrementX(int increment) {
            posX += increment;

            return this;
        }

        GamePos* incrementY(int increment) {
            posY += increment;
            
            return this;
        }
    
    private:
        int posX;
        int posY;
};

enum class DirectionState {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    STOP
};

class Direction {
    public:
        Direction() {
            dirX = 1;
            dirY = 0;
            state = DirectionState::RIGHT;
        }

        void toUp() {
            dirX = 0;
            dirY = 1;
            state = DirectionState::UP;
        }

        void toDown() {
            dirX = 0;
            dirY = -1;
            state = DirectionState::DOWN;
        }

        void toLeft() {
            dirX = -1;
            dirY = 0;
            state = DirectionState::LEFT;
        }

        void toRight() {
            dirX = 1;
            dirY = 0;
            state = DirectionState::RIGHT;
        }

        void stop()
        {
            dirX = 0;
            dirY = 0;
            state = DirectionState::STOP;
        }

        short getDirX() {
            return dirX;
        }

        short getDirY() {
            return dirY;
        }

        DirectionState getState() {
            return state;
        }

    private:
        short dirX;
        short dirY;
        DirectionState state;
};

class GameObject {
    public:
        GameObject(GamePos p, Direction d)
        {
            pos = p;
            direction = d;
        };

        GameObject(GamePos p)
        {
            pos = p;
            direction = Direction();
        }
        
        GameObject()
        {
            pos = GamePos();
            direction = Direction();
        }

        GamePos getPos()
        {
            return pos;
        }

        Direction getDir()
        {
            return direction;
        }

        void draw(void (*callback)(int x, int y))
        {
            callback(pos.getX(), pos.getY());
        }

    protected:
        GamePos pos;
        Direction direction;
};

class GameMap
{
    public:
        GameMap(int x, int y)
        {
            sizeX = x;
            sizeY = y;

            map = new GameObject**[x];
            for(int i; i < x; i++)
            {
                map[i] = new GameObject*[y];
                for (int j = 0; j < y; j++) {
                    map[i][j] = nullptr;
                }
            }
        }
        
        void addObject(GameObject* object)
        {
            GamePos pos = object->getPos();

            map[pos.getX()][pos.getY()] = object;
        }

        void removeObject(int x, int y)
        {
            if(map[x][y] == nullptr)
                return;

            map[x][y] = nullptr;
        }

        void removeObject(GameObject *object)
        {
            GamePos pos = object->getPos();
            map[pos.getX()][pos.getY()] = nullptr;
        }

        bool detectObject(int x, int y)
        {      
            return map[x][y] != nullptr;
        }

        bool detectObject(GameObject *object)
        {
            GamePos pos = object->getPos();
            return map[pos.getX()][pos.getY()] == object;
        }

    private:
        int sizeX;
        int sizeY;
        typedef GameObject*** Map;
        Map map;

};