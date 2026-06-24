class Twitter {
public:
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;
    int currentTime = 0;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        following[userId].insert(userId);
        tweets[userId].push_back({currentTime, tweetId});
        currentTime++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        priority_queue<pair<int, int>> mostRecentTweets;

        for(auto user:following[userId]){
            for(auto tweet:tweets[user]){
                mostRecentTweets.push(tweet);
            }
        }

        while(!mostRecentTweets.empty() && result.size()<10){
            result.push_back(mostRecentTweets.top().second);
            mostRecentTweets.pop();
        }

        return result;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followerId);
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId==followeeId){
            return;
        }
        following[followerId].erase(followeeId);
    }
};
