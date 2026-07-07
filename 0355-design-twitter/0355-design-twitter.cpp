class Twitter {
private:
    static int timestamp;
    struct Tweet {
        int tweetId;
        int time;
        Tweet* next;

        Tweet(int id) {
            tweetId = id;
            time = timestamp++;
            next = nullptr;
        }
    };

    struct User {
        int id;
        unordered_set<int> followed;
        Tweet* tweetHead;

        User(int id) {
            this->id = id;
            followed.insert(id); 
            tweetHead = nullptr;
        }

        void follow(int userId) {
            followed.insert(userId);
        }

        void unfollow(int userId) {
            if (userId != id)
                followed.erase(userId);
        }

        void post(int tweetId) {
            Tweet* tweet = new Tweet(tweetId);
            tweet->next = tweetHead;
            tweetHead = tweet;
        }
    };

    unordered_map<int, User*> users;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        if (!users.count(userId))
            users[userId] = new User(userId);

        users[userId]->post(tweetId);
    }

    vector<int> getNewsFeed(int userId) {

        vector<int> feed;

        if (!users.count(userId))
            return feed;

        auto cmp = [](Tweet* a, Tweet* b) {
            return a->time < b->time;
        };

        priority_queue<Tweet*, vector<Tweet*>, decltype(cmp)> pq(cmp);

        for (int followee : users[userId]->followed) {
            if (users.count(followee) && users[followee]->tweetHead)
                pq.push(users[followee]->tweetHead);
        }

        while (!pq.empty() && feed.size() < 10) {

            Tweet* curr = pq.top();
            pq.pop();

            feed.push_back(curr->tweetId);

            if (curr->next)
                pq.push(curr->next);
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {

        if (!users.count(followerId))
            users[followerId] = new User(followerId);

        if (!users.count(followeeId))
            users[followeeId] = new User(followeeId);

        users[followerId]->follow(followeeId);
    }

    void unfollow(int followerId, int followeeId) {

        if (!users.count(followerId))
            return;

        users[followerId]->unfollow(followeeId);
    }
};

int Twitter::timestamp = 0;