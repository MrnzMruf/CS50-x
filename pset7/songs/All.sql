-- 1.sql
SELECT "name" FROM "songs";
-- 2.sql
SELECT name FROM songs ORDER BY tempo ASC;
-- 3.sql
SELECT name FROM songs ORDER BY duration_ms DESC LIMIT 5;
-- 4.sql
SELECT name FROM songs WHERE danceability > 0.75 AND energy > 0.75 AND valence > 0.75;
-- 5.sql
SELECT AVG(energy) FROM songs;
-- 6.sql
SELECT name FROM songs WHERE artist_id IN (SELECT id FROM artists WHERE name = 'Post Malone');
-- 7.sql
SELECT AVG(energy) FROM songs WHERE artist_id IN (SELECT id FROM artists WHERE name = 'Drake');
-- 8.sql
SELECT name FROM songs WHERE name LIKE '%feat.%';
-- Answer: 
-- 1. Description of "Audio Aura":
-- Based on the data in the `songs.db` database, which contains the top 100 songs, this listener's "Audio Aura" can be described as follows:
-- - The average energy of the songs is 0.659, indicating a relatively energetic state.
-- - The average valence and danceability were not calculated in this data, but given the songs present, it can be expected that these values are also at a good level.
-- - Some songs feature collaborations with other artists, indicating diversity in the listener's musical taste.
-- Considering these values, it can be said that this listener's "Audio Aura" suggests liveliness and positive energy.
-- 2. Critiques on the Calculation of "Audio Aura":
-- This calculation may not provide a complete representation of the listener's personality or emotional states. For example:
-- - Some listened songs might have been chosen only for temporary reasons (like a specific mood on a particular day) rather than true liking.
-- - This method might limit the musical diversity of the individual and only includes hit songs heard for specific external reasons.
-- 3. Alternative Suggestions for Calculating "Audio Aura":
-- To enhance the calculation of "Audio Aura," the following suggestions could be beneficial:
-- - Analyzing songs over a larger timeframe (for example, several years) to obtain a more comprehensive view of the listener's preferences and emotional state.
-- - Considering the lyrics and themes of songs that may impact the listener's emotional condition.
-- - Utilizing user surveys or qualitative analyses to better understand the feelings and experiences of the listener in relation to the songs they have listened to.
