<?php
$db = new SQLite3('db.sqlite');

$db->exec("CREATE TABLE IF NOT EXISTS users (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    username TEXT,
    email TEXT
)");

$db->exec("DELETE FROM users;");
$db->exec("INSERT INTO users (username, email) VALUES ('haris', 'old@example.com');");

echo "Database initialized.";
