console.log('Before');
getUser(1, displayUser);
console.log('After');

function displayCommits(commits){
    console.log("Commits", commits);
}

function displayRepositories(repositories) {
    console.log("Repositories", repositories);
    getCommits(repositories[0], displayCommits);
}

function displayUser(getuser){
    console.log("User", getuser);
    getRepositories(getuser.username, displayRepositories);
}

function getUser(id, callback){
    setTimeout(() => {
        console.log('Reading Database');
        callback({id: id, username: "bprakashputta"});
    }, 2000);
}

function getRepositories(username, callback) {
    console.log("GitHub Username: "+ username);
    // Get list of all repositories by making get request to GitHub.
    repos = [{name:"repo1", commits:[{id: "1",name:"cm1"},{id: "2",name:"cm2"}] },{name:"repo2", commits:"commit2"}, {name:"repo3", commits:"commit3"}];
    callback(repos);
}

function getCommits(repository, callback) {
    console.log("Repository Name: ", repository.name);
    commits = repository.commits;
    callback(commits);
}