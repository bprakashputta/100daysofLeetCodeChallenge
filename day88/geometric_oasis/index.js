$(document).ready(function() {
    $('#play-video').on('click', function(event) {

        // $("#video").trigger('play');
        // $("#video").trigger('pause');
        $("#video")[0].src += "?autoplay=1";
        // event.preventDefault();
        // this.paused ? this.play() : this.pause();
    });
});