<link rel="stylesheet" type="text/css" media="screen" href="/src/common/header/style.css" />
<header>
  <nav class="nav-box-shadow navbar is-fixed-top is-small">
    <div class="container">
      <div class="navbar-brand">
        <a class="navbar-item" href="/">
          <img src="/src/common/header/assets/logo.png" alt="Camagru">
        </a>
        <div id="navBurger" class="navbar-burger burger">
          <span></span><span></span><span></span>
        </div>
      </div>
      <div id="navMenu" class="navbar-menu">
        <div class="navbar-end">
          <?php
            if ($_SESSION['isLogged']) {
              echo '<a class="navbar-item" href="/">Home</a>
                <a class="navbar-item" href="/src/gallery">Gallery</a>
                <div id="navDropDown" class="navbar-item has-dropdown">
                  <a class="navbar-link">Settings</a>
                  <div class="navbar-dropdown">
                    <a class="navbar-item is-size-6" href="/src/account">
                      My account
                    </a>
                    <a class="navbar-item is-size-6" href="/src/authentication/logout">
                      Logout
                    </a>
                    <hr class="navbar-divider">
                  </div>
                </div>
              ';
            }
          ?>
        </div>
      </div>
    </div>
  </nav>
</header>
<script type="text/javascript" src="/src/common/header/events.js"></script>   
