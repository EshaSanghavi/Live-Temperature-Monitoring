<div id="page"></div>

<script src="http://code.jquery.com/jquery-latest.min.js"></script>
<script>
    var RefreshTimerInterval = 10000; //10 secs
    $(document).ready(getData);

    function getData()
    {
        $.get('sensor_data.php', function(result)
        {
            $('#page').html(result);
            setTimeout(getData, RefreshTimerInterval);
        })
    }
</script>