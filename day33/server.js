console.log('Before');
// getUser(1, displayUser);
console.log('After');

// Consume the promises
// Promises Approach
// getUser(1)
//     .then(user => getRepositories(user.username))
//     .then(repos => getCommits(repos[0]))
//     .then(commits => console.log("Commits: ", commits))
//     .catch(error => console.log(error));


// Async, Await Approach\
displayCommits();

async function displayCommits() {
    const user = await getUser(1);
    const repos = await getRepositories(user.username);
    const commits = await getCommits(repos[0]);
    console.log("Commits", commits);
}

// function displayCommits(commits) {
//     console.log("Commits", commits);
// }

function displayRepositories(repositories) {
    console.log("Repositories", repositories);
    getCommits(repositories[0], displayCommits);
}

function displayUser(getuser){
    console.log("User", getuser);
    getRepositories(getuser.username, displayRepositories);
}

function getUser(id){
    return new Promise((resolve, reject)=>{
        setTimeout(() => {
            console.log('Reading Database');
            resolve({id: id, username: "bprakashputta"});
        }, 2000);
    });
}

function getRepositories(username) {
    return new Promise((resolve, reject)=>{
        setTimeout(()=>{
            console.log("GitHub Username: "+ username);
            // Get list of all repositories by making get request to GitHub.
            repos = [{name:"repo1", commits:[{id: "1",name:"cm1"},{id: "2",name:"cm2"}] },{name:"repo2", commits:"commit2"}, {name:"repo3", commits:"commit3"}];
            resolve(repos);
            // reject( new Error("message"));
        }, 2000);
    });
}

function getCommits(repository) {
    return new Promise((resolve, reject) => {
        setTimeout(()=>{
            console.log("Repository Name: ", repository.name);
            commits = repository.commits;
            resolve(commits);
        },2000);
    });
}