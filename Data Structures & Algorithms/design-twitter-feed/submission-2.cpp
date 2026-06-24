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
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> mostRecentTweets;

        for(auto user:following[userId]){
            for(auto tweet:tweets[user]){
                if(mostRecentTweets.size()<10){
                    mostRecentTweets.push(tweet);
                }
                else if(tweet.first>mostRecentTweets.top().first){
                    mostRecentTweets.pop();
                    mostRecentTweets.push(tweet);
                }
            }
        }

        vector<int> result(mostRecentTweets.size(), 0);

        for(int i=result.size()-1; i>=0; i--){
            result[i] = mostRecentTweets.top().second;
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
