<!DOCTYPE html>
<html lang="uk">
<head>
  <meta charset="UTF-8">
  <title>Кіносервіс</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      margin: 0;
      padding: 0;
      background: #f9f9f9;
    }
    header {
      background: #222;
      color: white;
      padding: 20px;
      text-align: center;
    }
    nav {
      background: #444;
      padding: 10px;
      text-align: center;
    }
    nav a {
      color: white;
      margin: 0 15px;
      text-decoration: none;
      font-weight: bold;
    }
    section {
      padding: 30px;
      max-width: 1100px;
      margin: auto;
    }
    h2 {
      text-align: center;
      color: #333;
    }

    .movies {
      display: flex;
      flex-wrap: wrap;
      justify-content: center;
      gap: 20px;
    }
    .movie {
      background: white;
      border-radius: 8px;
      width: 220px;
      box-shadow: 0 2px 6px rgba(0,0,0,0.1);
      text-align: center;
    }
    .movie img {
      width: 100%;
      height: 300px;
      object-fit: cover;
      border-radius: 8px 8px 0 0;
    }
    .movie p {
      margin: 10px;
    }

    table {
      width: 100%;
      border-collapse: collapse;
      margin-top: 20px;
    }
    th, td {
      padding: 12px;
      border: 1px solid #ccc;
      text-align: center;
    }
    th {
      background: #eee;
    }

    form {
      max-width: 500px;
      margin: auto;
      background: white;
      padding: 20px;
      border-radius: 8px;
      box-shadow: 0 2px 6px rgba(0,0,0,0.1);
    }
    label {
      display: block;
      margin-top: 15px;
      font-weight: bold;
    }
    select, input {
      width: 100%;
      padding: 10px;
      margin-top: 5px;
    }
    button {
      margin-top: 20px;
      background: #1976d2;
      color: white;
      border: none;
      padding: 12px;
      width: 100%;
      font-size: 16px;
      cursor: pointer;
      border-radius: 5px;
    }

    .contact-info p {
      font-size: 16px;
      margin: 10px 0;
    }

    footer {
      background: #222;
      color: white;
      text-align: center;
      padding: 20px;
      margin-top: 40px;
    }
    footer a {
      color: #90caf9;
      margin: 0 10px;
      text-decoration: none;
    }

    /* --- Модальне вікно --- */
    .modal {
      display: none;
      position: fixed;
      z-index: 999;
      left: 0;
      top: 0;
      width: 100%;
      height: 100%;
      overflow: auto;
      background-color: rgba(0,0,0,0.5);
    }
    .modal-content {
      background-color: #fff;
      margin: 15% auto;
      padding: 30px;
      border: 1px solid #888;
      width: 90%;
      max-width: 400px;
      text-align: center;
      border-radius: 10px;
      box-shadow: 0 4px 8px rgba(0,0,0,0.3);
    }
    .modal-content h3 {
      margin-bottom: 20px;
    }
    .close-btn {
      background-color: #1976d2;
      color: white;
      border: none;
      padding: 10px 20px;
      font-size: 16px;
      border-radius: 5px;
      cursor: pointer;
    }
  </style>
</head>
<body>

  <header>
    <h1>🎬 Кіносервіс</h1>
    <p>Онлайн сервіс купівлі квитків у кінотеатр</p>
  </header>

  <nav>
    <a href="#movies">Фільми</a>
    <a href="#schedule">Розклад</a>
    <a href="#tickets">Купити квиток</a>
    <a href="#contacts">Контакти</a>
  </nav>

  <section id="movies">
    <h2>🎞 Актуальні фільми</h2>
    <div class="movies">
      <div class="movie">
        <img src="https://upload.wikimedia.org/wikipedia/en/6/6e/Oppenheimer_%282023%29.jpg" alt="Оппенгеймер">
        <p><strong>Оппенгеймер</strong><br>Драма, Історичний — 180 хв</p>
      </div>
      <div class="movie">
        <img src="https://upload.wikimedia.org/wikipedia/en/0/0e/Guardians_of_the_Galaxy_Vol_3_poster.jpg" alt="Вартові Галактики 3">
        <p><strong>Вартові Галактики 3</strong><br>Фантастика, Пригоди — 150 хв</p>
      </div>
      <div class="movie">
        <img src="https://upload.wikimedia.org/wikipedia/en/0/0b/Barbie_2023_poster.jpg" alt="Барбі">
        <p><strong>Барбі</strong><br>Комедія, Фентезі — 110 хв</p>
      </div>
      <div class="movie">
        <img src="https://upload.wikimedia.org/wikipedia/en/b/bc/Interstellar_film_poster.jpg" alt="Інтерстеллар">
        <p><strong>Інтерстеллар</strong><br>Фантастика, Драма — 169 хв</p>
      </div>
    </div>
  </section>

  <section id="schedule">
    <h2>🗓 Розклад сеансів</h2>
    <table>
      <tr>
        <th>Фільм</th>
        <th>Дата</th>
        <th>Час</th>
        <th>Зал</th>
      </tr>
      <tr>
        <td>Оппенгеймер</td>
        <td>14.07.2025</td>
        <td>18:00</td>
        <td>Зал 1</td>
      </tr>
      <tr>
        <td>Барбі</td>
        <td>14.07.2025</td>
        <td>15:00</td>
        <td>Зал 2</td>
      </tr>
      <tr>
        <td>Вартові Галактики 3</td>
        <td>15.07.2025</td>
        <td>20:00</td>
        <td>Зал 1</td>
      </tr>
    </table>
  </section>

  <section id="tickets">
    <h2>🎟 Купити квиток</h2>
    <form>
      <label for="film">Фільм</label>
      <select id="film">
        <option>Оппенгеймер</option>
        <option>Барбі</option>
        <option>Вартові Галактики 3</option>
        <option>Інтерстеллар</option>
      </select>

      <label for="date">Дата</label>
      <input type="date" id="date">

      <label for="time">Час</label>
      <select id="time">
        <option>12:00</option>
        <option>15:00</option>
        <option>18:00</option>
        <option>21:00</option>
      </select>

      <label for="count">Кількість квитків</label>
      <input type="number" id="count" min="1" max="10" value="1">

      <button type="submit">Оформити замовлення</button>
    </form>
  </section>

  <section id="contacts">
    <h2>📞 Контакти</h2>
    <div class="contact-info">
      <p>Телефон: +380 67 123 4567</p>
      <p>Ел. пошта: support@kinoservice.ua</p>
      <p>Адреса: м. Київ, вул. Кіношна, 7</p>
      <p>Графік роботи: щодня з 10:00 до 22:00</p>
    </div>
  </section>

  <footer>
    <p>© 2025 Кіносервіс. Усі права захищено.</p>
    <p>
      <a href="#">Facebook</a> |
      <a href="#">Instagram</a> |
      <a href="#">Telegram</a>
    </p>
  </footer>

  <!-- Модальне вікно -->
  <div id="confirmationModal" class="modal">
    <div class="modal-content">
      <h3>✅ Бронювання завершено!</h3>
      <p>Дякуємо за замовлення. Ваші квитки вже в обробці.</p>
      <button class="close-btn" onclick="closeModal()">ОК</button>
    </div>
  </div>

  <!-- Скрипт -->
  <script>
    const form = document.querySelector("form");
    const modal = document.getElementById("confirmationModal");

    form.addEventListener("submit", function(event) {
      event.preventDefault();
      modal.style.display = "block";
      form.reset();
    });

    function closeModal() {
      modal.style.display = "none";
    }

    window.onclick = function(event) {
      if (event.target === modal) {
        modal.style.display = "none";
      }
    }
  </script>

</body>
</html>
