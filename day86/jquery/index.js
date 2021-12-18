$('h1').css("color", "red");


$("a").attr("href", "https://www.yahoo.com/");

// $(document).keypress(function(event) {
//     console.log(event.key);
//     $("h1").text(event.key);
// })

$("button").on("click", function() {
    // $("h1").animate({ margin: "50px", color: "blue" });
    $("h1").slideUp().slideDown().animate({ opacity: "0.5" });
})