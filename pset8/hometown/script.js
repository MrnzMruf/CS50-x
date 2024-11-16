document.addEventListener('DOMContentLoaded', function() {  
    var dropdowns = document.querySelectorAll('.dropdown-toggle');  
    dropdowns.forEach(function(dropdown) {  
        dropdown.addEventListener('mouseenter', function() {  
            var menu = this.nextElementSibling;  
            menu.classList.add('show');  
        });  

        dropdown.addEventListener('mouseleave', function() {  
            var menu = this.nextElementSibling;  
            menu.classList.remove('show');  
        });  
    });  
});
