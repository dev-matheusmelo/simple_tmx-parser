<h1>Simple_tmx_parser</h6>
<h2>About:</h2>
<h2>
  Simple_tmx_parser is a C/CPP lib that parser any tag atribute or data you want from any tmx file(tiled project file) to use in your code.
</h2>
<h2>Usage:</h2>
Simple include the .hpp file in your project and use the class like this.<br><br>
<code>simple_tmx_parser yourfile("pathoffile.tmx");</code>  <br><br>
and use the member functions you want to extract any data from file to your variable in your project:<br><br>
<code>auto my_var = yourfile.get_atribute_value("tag_that_you_want","atribute_name"); <br></code>
<br><br>Example:<br><br>
<code>std::string map_width_value = yourfile.get_atribute_value("map","width"); //to get atribute from tag </code>
<br><br>Example to get data of your map from layer:<br><br>
<code>auto data_from_layer_1 = yourfile.get_layer_data(std::string layer_id,tmx_encoding encoding);<br> //wil return a std::vector of data from layer tag</code><br><br>
usage:<br><br>
<code>auto data_from_layer_1 = yourfile.get_layer_data("1",tmx_encoding::ENCODING_CSV);</code>
