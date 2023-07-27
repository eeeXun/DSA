class Solution {
private:
    void dfs(vector<vector<int>>& rooms, vector<bool>& keys, int roomID)
    {
        if (keys.at(roomID))
            return;
        keys.at(roomID) = true;

        for (auto room : rooms.at(roomID)) {
            dfs(rooms, keys, room);
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        vector<bool> keys(rooms.size(), false);
        dfs(rooms, keys, 0);

        for (auto key : keys) {
            if (!key)
                return false;
        }
        return true;
    }
};
